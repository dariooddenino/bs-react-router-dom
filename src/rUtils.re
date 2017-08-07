type routeConfirmFunction = string => (Js.boolean => unit) => unit;

type match 'a = Js.t({..
  isExact: bool,
  path: string,
  url: string,
  params: Js.t({.. })
} as 'a);

type location 'a = Js.t({..
  pathname: string,
  search: string,
  hash: string,
  key: string,
  state: Js.t({.. })
} as 'a);

type isActiveFunction 'a 'b = match 'a => location 'b => Js.boolean;

let fromOpt = Js_null_undefined.from_opt;

let toJsBoolean = Js_boolean.to_js_boolean;

type jsTo 'a = Js.t ({.. pathname : string} as 'a);

let getTo (s: option string) (o: option (jsTo 'a)) =>
  switch (s, o) {
  | (Some s, _) => { "pathname": s }
  | (_, Some o) => o
  | _ => {"pathname": "/"}
  };

