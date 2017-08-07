open RUtils;

external memory_router : ReasonReact.reactClass = "MemoryRouter" [@@bs.module "react-router-dom"];

/** @TODO: initialEntries */
let make
    initialIndex::(iI: option int)=?
    getUserConfirmation::(gU: option routeConfirmFunction)
    keyLength::(kL: option int)=?
    /** initialEntries: array string / obj */
    children =>
  ReasonReact.wrapJsForReason
    reactClass::memory_router
    props::{"initialIndex": fromOpt iI, "getUserConfirmation": fromOpt gU, "keyLength": fromOpt kL}
    children;
