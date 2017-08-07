external switch_component : ReasonReact.reactClass = "Switch" [@@bs.module "react-router-dom"];

let make children =>
  ReasonReact.wrapJsForReason reactClass::switch_component props::(Js.Obj.empty ()) children;
