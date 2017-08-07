open RUtils;

external browser_router : ReasonReact.reactClass =
  "BrowserRouter" [@@bs.module "react-router-dom"];

let make
    basename::(bN: option string)=?
    getUserConfirmation::(gU: option routeConfirmFunction)=?
    forceRefresh::(fR: bool)=false
    keyLength::(kL: option int)=?
    children =>
  ReasonReact.wrapJsForReason
    reactClass::browser_router
    props::{
      "basename": fromOpt bN,
      "forceRefresh": toJsBoolean fR,
      "keyLength": fromOpt kL,
      "getUserConfirmation": fromOpt gU
    }
    children;

