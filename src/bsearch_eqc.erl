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


prop_binsearch3() ->
    ?SETUP(fun () -> eqc_c:start(bsearch),
                     fun() -> ok end
           end,
    ?FORALL({K, L}, {int(), list(int())},
            begin
                P = eqc_c:create_array(int, L),
                S = length(L),

                equals(index(L, K, 0),
                       bsearch:binsearch3(P, S, K))
            end)).
