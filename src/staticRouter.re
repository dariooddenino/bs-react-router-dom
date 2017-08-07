open RUtils;

external static_router : ReasonReact.reactClass =
  "StaticRouter" [@@bs.module "react-router-dom"];

/** @TODO: complete */

let make
    basename::(bN: option string)=?
    /** location: string | object */
    /** context: object */
    children =>
    ReasonReact.wrapJsForReason
    props::{
      "basename": fromOpt bN
    }
    children;
