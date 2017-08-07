open RUtils;

external hash_router: ReasonReact.reactClass =
  "HashRouter" [@@bs.module "react-router-dom"];

let make
  baseName::(bN: option string)=?
  getUserConfirmation::(gU: option routeConfirmFunction)=?
  hashType::(hT: string)="slash"
  children =>
  ReasonReact.wrapJsForReason
  reactClass::hash_router
  props::{
    "basename": fromOpt bN,
    "hashType": hT,
    "getUserConfirmation": fromOpt gU
  }
  children;
