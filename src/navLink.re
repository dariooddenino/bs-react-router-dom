open RUtils;

external nav_link : ReasonReact.reactClass = "NavLink" [@@bs.module "react-router-dom"];

let make
    _to::(t: option string)=?
    toObj::(tO: option (jsTo 'a))=?
    replace::(r: bool)=false
    activeClassName::(aCN: string)="active"
    activeStyle::(aS)=?
    exact::(e: bool)=false
    strict::(s: bool)=false
    isActive::(iA: option (isActiveFunction 'b 'c))=?
    location::(l: option (location 'c))=?
    children =>
  ReasonReact.wrapJsForReason
    reactClass::nav_link
    props::{
      "to": (getTo t tO),
      "replace": toJsBoolean r,
      "activeClassName": aCN,
      "activeStyle": fromOpt aS,
      "exact": toJsBoolean e,
      "strict": toJsBoolean s,
      "isActive": fromOpt iA,
      "location": fromOpt l
    }
    children;
