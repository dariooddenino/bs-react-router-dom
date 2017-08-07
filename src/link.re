open RUtils;

external link : ReasonReact.reactClass = "Link" [@@bs.module "react-router-dom"];

let make
    _to::(t: option string)=?
    toObj::(tO: option (jsTo 'a))=?
    replace::(r: bool)=false
    children =>
  ReasonReact.wrapJsForReason
    reactClass::link
    props::{
      "to": (getTo t tO),
      "replace": toJsBoolean r
    }
    children;
