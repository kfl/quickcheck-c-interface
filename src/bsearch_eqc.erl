%%%
%%% QuickCheck example, checking properties some C code
%%%
%%% Created by Ken Friis Larsen <kflarsen@diku.dk>

-module(bsearch_eqc).
-include_lib("eqc/include/eqc.hrl").
-compile(export_all).


index([], _K, _I) ->
    -1;
index([K | _T], K, I) ->
    I;
index([_ | T], K, I) ->
    index(T, K, I+1).


prop_binsearch() ->
    ?SETUP(fun () -> eqc_c:start(bsearch),
                     fun() -> ok end
           end,
    ?FORALL({K, L}, {int(), list(int())},
            begin
                Sorted = lists:usort(L),
                P = eqc_c:create_array(int, Sorted),
                Size = length(Sorted),

                equals(index(Sorted, K, 0),
                       bsearch:binsearch4(P, Size, K))
            end)).



% Version, where we with much higher probability generate keys
% actually found in the list/
prop_binsearch_better_examples() ->
    ?SETUP(fun () -> eqc_c:start(bsearch),
                     fun() -> ok end
           end,
    ?FORALL(L, list(int()),
    ?LETSHRINK(K, good_key(L),
            begin
                Sorted = lists:usort(L),
                P = eqc_c:create_array(int, Sorted),
                Size = length(Sorted),

                ?WHENFAIL(io:format("Trying to find key: ~p~n", [K]),
                equals(index(Sorted, K, 0),
                       bsearch:binsearch4(P, Size, K)))
            end))).

good_key(L) ->
    frequency([ {1, int()} | 
                [ {9, elements(L)} || L /= [] ]]
              ).
