open RUtils;

external redirect: ReasonReact.reactClass = "Link" [@@bs.module "react-router-dom"];

let make
  _to::(t: option string)=?
  toObj::(tO: option (jsTo 'a))=?
  push::(p: bool)=false
  from::(f: option string)=?
  _ =>
ReasonReact.wrapJsForReason
  reactClass::redirect
  props::{
    "to": (getTo t tO),
    "push": toJsBoolean p,
    "replace": fromOpt f
  }
  [||];
