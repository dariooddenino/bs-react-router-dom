open RUtils;

let _wrapComponent cMake jsProps =>
    ReasonReact.element (cMake match::jsProps##_match location::jsProps##location history::jsProps##history [||]);

external route : ReasonReact.reactClass = "Route" [@@bs.module "react-router-dom"];

let make
    path::(path: string)
    ::componentMake
    exact::(exact: bool)=false
    _ =>
  ReasonReact.wrapJsForReason
    reactClass::route
    props::{
      "path": path,
      "exact": toJsBoolean exact,
      "component": _wrapComponent componentMake
    }
    [||];
