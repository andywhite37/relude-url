module P = ReludeParse.Parser;
open P.Infix;

type t =
  | QueryKey(string);

let make = str => QueryKey(str);

let parser: P.t(t) =
  P.many1(P.anyCharNotIn(["="]))
  <#> Relude.Nel.toList
  <#> Relude.List.String.join
  <#> make;

let show = (QueryKey(str)) => str;

module Show: BsAbstract.Interface.SHOW with type t = t = {
  type nonrec t = t;
  let show = show;
};