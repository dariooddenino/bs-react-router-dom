open RUtils;

external prompt : ReasonReact.reactClass = "Prompt" [@@bs.module "react-router-dom"];

let make
  message::(m: option string)=?
  /* messageFunc */
  _when::(w: bool)=false
  _ =>
 ReasonReact.wrapJsForReason
  reactClass::prompt
  props::{
    "message": fromOpt m,
    "when": toJsBoolean w
  }
  [||];
