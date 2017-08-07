module One = {
  let component = ReasonReact.statelessComponent "One";

  let make ::match ::location ::history _ => {
    ...component,
    render: fun _ => {
      <div>(ReasonReact.stringToElement "Page 1")</div>
    }
  }
};

 module Two = {
  let component = ReasonReact.statelessComponent "Two";

  let make ::match ::location ::history _ => {
    ...component,
    render: fun _ =>
      <div>
        (ReasonReact.stringToElement "Page 2")
        /* <Prompt message="Ciao" _when=true /> */
        </div>
  };
};


module App = {
  let component = ReasonReact.statelessComponent "App";

  let activeStyle = { "color": "red" };


  let make _ => {
    ...component,
    render: fun _ =>
      <BrowserRouter>
        <div>
           <NavLink activeStyle exact=true strict=true _to="/">(ReasonReact.stringToElement "PAGE 1")</NavLink>
           <NavLink activeStyle exact=true strict=true toObj={"pathname": "/2"}>(ReasonReact.stringToElement "PAGE 2")</NavLink>
          <Switch>
            <Route exact=true path="/" componentMake=One.make />
            <Route path="/2" componentMake=Two.make />
          </Switch>
        </div>
      </BrowserRouter>
  }
};

ReactDOMRe.renderToElementWithId <App /> "app";
