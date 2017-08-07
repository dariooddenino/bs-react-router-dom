external router : ReasonReact.reactClass = "Router" [@@bs.module "react-router-dom"];

/** @TODO: history */

let make ::history children => ReasonReact.wrapJsForReason props::{"history": history} children;
