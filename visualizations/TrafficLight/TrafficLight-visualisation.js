import TrafficLight from "./TrafficLight.js";
import {SelectError} from "./btypes/BUtils.js";
import {colors} from "./TrafficLight.js"

import {enum_colors} from "./TrafficLight.js"

import {BTuple} from "./btypes/BTuple.js";
import {BSet} from "./btypes/BSet.js";
import {BBoolean} from "./btypes/BBoolean.js";
import {BObject} from "./btypes/BObject.js";
import {BString} from "./btypes/BString.js";

var _machine = new TrafficLight();
var _state_list = [];
var _transition_list = [];
var _included_machines = {};
_included_machines["TrafficLight"] = function(){return _machine};
var _state_view_vars = document.getElementById("_state_view_variables");
var _state_view_consts = document.getElementById("_state_view_constants");
var _state_view_sets = document.getElementById("_state_view_sets");
var _state_view_invariant = document.getElementById("_state_view_invariant");
var _svg_vars = {}
_svg_vars["cars_green"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_green")
_svg_vars["peds_green"] = document.getElementById("traffic_light").contentDocument.getElementById("peds_green")
_svg_vars["peds_red"] = document.getElementById("traffic_light").contentDocument.getElementById("peds_red")
_svg_vars["cars_red"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_red")
_svg_vars["cars_yellow_1"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_yellow_1")
_svg_vars["cars_yellow_2"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_yellow_2")
var _machine_vars = {}
var _var_label;
var _var_div;
_var_div = document.createElement("div");
_var_div.innerHTML = _included_machines["TrafficLight"]()._get_tl_cars();
_var_div.id = "_var_tl_cars";
_machine_vars["tl_cars"] = _var_div;
_var_label = document.createElement("label");
_var_label.htmlFor = "_var_tl_cars";
_var_label.innerHTML = "TrafficLight.tl_cars";
_state_view_vars.appendChild(_var_label);
_state_view_vars.appendChild(_var_div);
_var_div = document.createElement("div");
_var_div.innerHTML = _included_machines["TrafficLight"]()._get_tl_peds();
_var_div.id = "_var_tl_peds";
_machine_vars["tl_peds"] = _var_div;
_var_label = document.createElement("label");
_var_label.htmlFor = "_var_tl_peds";
_var_label.innerHTML = "TrafficLight.tl_peds";
_state_view_vars.appendChild(_var_label);
_state_view_vars.appendChild(_var_div);
_var_div = document.createElement("div");
_var_div.innerHTML = _included_machines["TrafficLight"]()._get__colors();
_var_div.id = "_var_colors";
_machine_vars["colors"] = _var_div;
_var_label = document.createElement("label");
_var_label.htmlFor = "_var_colors";
_var_label.innerHTML = "TrafficLight.colors";
_state_view_sets.appendChild(_var_label);
_state_view_sets.appendChild(_var_div);
_var_div = document.createElement("div");
_var_div.innerHTML = _included_machines["TrafficLight"]()._check_inv_1();
_var_div.id = "_check_inv_1";
_machine_vars["_check_inv_1"] = _var_div;
_var_label = document.createElement("label");
_var_label.htmlFor = "_check_inv_1";
_var_label.innerHTML = "tl_cars:colors";
_state_view_invariant.appendChild(_var_label);
_state_view_invariant.appendChild(_var_div);
_var_div = document.createElement("div");
_var_div.innerHTML = _included_machines["TrafficLight"]()._check_inv_2();
_var_div.id = "_check_inv_2";
_machine_vars["_check_inv_2"] = _var_div;
_var_label = document.createElement("label");
_var_label.htmlFor = "_check_inv_2";
_var_label.innerHTML = "tl_peds:{red,green}";
_state_view_invariant.appendChild(_var_label);
_state_view_invariant.appendChild(_var_div);
_var_div = document.createElement("div");
_var_div.innerHTML = _included_machines["TrafficLight"]()._check_inv_3();
_var_div.id = "_check_inv_3";
_machine_vars["_check_inv_3"] = _var_div;
_var_label = document.createElement("label");
_var_label.htmlFor = "_check_inv_3";
_var_label.innerHTML = "tl_peds=redortl_cars=red";
_state_view_invariant.appendChild(_var_label);
_state_view_invariant.appendChild(_var_div);

function updateVisuals () {
  _svg_vars["cars_green"].setAttribute("fill", (_machine._get_tl_cars().equal(new colors(enum_colors.green)).booleanValue() ? new BString("green") : new BString("black")).getValue());
  _svg_vars["peds_red"].setAttribute("fill", (_machine._get_tl_peds().equal(new colors(enum_colors.red)).booleanValue() ? new BString("red") : new BString("black")).getValue());
  _svg_vars["cars_yellow_2"].setAttribute("visibility", (_machine._get_tl_cars().unequal(new colors(enum_colors.red)).booleanValue() ? new BString("visible") : new BString("hidden")).getValue());
  _svg_vars["cars_yellow_1"].setAttribute("fill", (new BBoolean(_machine._get_tl_cars().equal(new colors(enum_colors.yellow)).booleanValue() || _machine._get_tl_cars().equal(new colors(enum_colors.redyellow)).booleanValue()).booleanValue() ? new BString("yellow") : new BString("black")).getValue());
  _svg_vars["cars_yellow_2"].setAttribute("fill", (new BBoolean(_machine._get_tl_cars().equal(new colors(enum_colors.yellow)).booleanValue() || _machine._get_tl_cars().equal(new colors(enum_colors.redyellow)).booleanValue()).booleanValue() ? new BString("yellow") : new BString("black")).getValue());
  _svg_vars["cars_yellow_1"].setAttribute("visibility", (_machine._get_tl_cars().unequal(new colors(enum_colors.green)).booleanValue() ? new BString("visible") : new BString("hidden")).getValue());
  _svg_vars["peds_green"].setAttribute("fill", (_machine._get_tl_peds().equal(new colors(enum_colors.green)).booleanValue() ? new BString("green") : new BString("black")).getValue());
  _svg_vars["cars_red"].setAttribute("fill", (new BBoolean(_machine._get_tl_cars().equal(new colors(enum_colors.red)).booleanValue() || _machine._get_tl_cars().equal(new colors(enum_colors.redyellow)).booleanValue()).booleanValue() ? new BString("red") : new BString("black")).getValue());
  _machine_vars["tl_cars"].innerHTML = _included_machines["TrafficLight"]()._get_tl_cars();
  _machine_vars["tl_peds"].innerHTML = _included_machines["TrafficLight"]()._get_tl_peds();
  for (let i = 1; i <= 3; i++) {
    _machine_vars["_check_inv_"+i].innerHTML = _machine["_check_inv_"+i]();
  }
  checkTransitions();
}

var _history_view_buttons = document.getElementById("_history_view_buttons");
var _buttonLeft = document.createElement("button");
var _buttonRight = document.createElement("button");
var _buttonUpload = document.createElement("button");
var _buttonExport = document.createElement("button");
var _inputUpload = document.createElement("input");
var _buttonRun10 = document.createElement("button");
var _buttonRun500 = document.createElement("button");

function flattenTuple(tuple) {
    if(!(tuple instanceof BTuple)) {
        return [tuple];
    }
    return [tuple.projection1(), ...flattenTuple(tuple.projection2())];
}

function createOptionList(event, transition) {
    let collator = new Intl.Collator([], {numeric: true});
    for(let index in _machine_events[event].parameterNames) {
        let parameter = _machine_events[event].parameterNames[index];
        var datalist = document.querySelector("#" + event + "_" + parameter + "_datalist");
        datalist.replaceChildren();
        for(let value of Array.of(...transition).sort((a, b) => collator.compare(a, b))) {
            let option = document.createElement("option");
            value = flattenTuple(value);
            option.text = value[index].toString();
            datalist.appendChild(option);
        }
    }
}

function checkTransitions () {
    let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
    for(event in _machine_events) {
      var transition;
      if(_transition_list[index]?.[event] == null ?? true) {
         transition = _machine["_tr_" + event]();
         _transition_list[index][event] = transition;
      } else {
         transition = _transition_list[index][event];
      }
      if(!(transition instanceof BSet)) {
        _machine_events[event].disabled = !transition;
      } else if (transition.size().intValue() == 0) {
        _machine_events[event].disabled = true;
      } else {
        let collator = new Intl.Collator([], {numeric: true});
        for(let current_transition of transition) {
            try {
                var current_machine = _machine._copy();
                current_machine[event](...flattenTuple(current_transition));
            } catch (error) {
                  if(! error instanceof SelectError) {
                      throw error;
                  }
                  transition = transition.difference(new BSet(current_transition));
            }
        }
        if(transition.size().intValue() == 0) {
            _machine_events[event].disabled = true;
        } else {
            _machine_events[event].disabled = false;
        }
        createOptionList(event, transition);
      }
    }
    _buttonLeft.disabled = document.querySelector(".active").index <= 0;
    _buttonRight.disabled = document.querySelector(".active").index >= document.querySelector("span:last-of-type").index;
}

_operations_view = document.getElementById("_operations_view");
_history_view = document.getElementById("_history_view");
_scenario_view = document.getElementById("_scenario_view");

var _history_onclick_function = function () {
  _machine = _state_list[this.index]._copy();
  document.querySelectorAll("span").forEach(el => el.classList.remove("active"));
  this.classList.add("active");
  updateVisuals();
}

function createHistoryElement(text, index) {
  var history_element = document.createElement("span");
  history_element.innerHTML = text + "</br>";
  history_element.index = index;
  document.querySelectorAll("span.active").forEach(element => element.classList.remove("active"));
  history_element.classList.add("active");
  history_element.onclick = _history_onclick_function;
  _state_list = _state_list.slice(0, index);
  _state_list.push(_machine._copy());
  _transition_list = _transition_list.slice(0, index);
  _transition_list.push({});
  while(_history_view.querySelectorAll("span").length > index && _history_view.lastChild !== null) {
    _history_view.removeChild(_history_view.lastChild);
  }
  _history_view.appendChild(history_element);
}

function selectHistoryElement(offset) {
  let currentHistoryElement = _history_view.querySelector(".active");
  let index = currentHistoryElement.index + offset;
  if (index < 0 || index >= _state_list.length) {
    return;
  }
  currentHistoryElement.classList.remove("active");
  _machine = _state_list[index]._copy();
  _history_view.querySelectorAll(".active").forEach(el => el.classList.remove("active"));
  currentHistoryElement = _history_view.querySelector("span:nth-of-type(" + (index + 1) + ")");
  currentHistoryElement.classList.add("active");
  updateVisuals();
}

function createScenarioElement(text, trace) {
  var scenario_element = document.createElement("button");
  var remove_element = document.createElement("button");
  scenario_element.innerHTML = text + "</br>";
  remove_element.innerHTML = "X";
  var div_element = document.createElement("div");
  div_element.appendChild(scenario_element);
  div_element.appendChild(remove_element);
  _scenario_view.appendChild(div_element);
  scenario_element.onclick = function() {
    displayTrace(trace);
  };
  remove_element.onclick = function() {
    _scenario_view.removeChild(div_element);
  };
}


_buttonLeft.innerHTML="&#9664;";
_buttonLeft.onclick = function(){selectHistoryElement(-1)};
_buttonRight.innerHTML="&#9654;";
_buttonRight.onclick = function(){selectHistoryElement(1)};
_history_view_buttons.appendChild(_buttonLeft);
_history_view_buttons.appendChild(_buttonRight);

_buttonUpload.textContent = "Import trace";
_buttonUpload.onclick = importTrace;
_history_view_buttons.appendChild(_buttonUpload);

_buttonExport.textContent = "Export trace";
_buttonExport.onclick = exportTrace;
_history_view_buttons.appendChild(_buttonExport);

_buttonRun10.textContent = "Run trace(10ms)";
_buttonRun10.onclick = function(){runTrace(10);};
_history_view_buttons.appendChild(_buttonRun10);

_buttonRun500.textContent = "Run trace(500ms)";
_buttonRun500.onclick = function(){runTrace(500);};
_history_view_buttons.appendChild(_buttonRun500);

createHistoryElement("Initialisation", 0);
var _current_trace = [{name: "$initialise_machine", params: {}}];

var _param_div;
var _param_datalist;
var _onclick_function;
var _machine_events = {};
var _svg_events = {};
_param_div = document.createElement("div");
_param_div.classList.add("param");
_machine_events["cars_g"] = document.createElement("button");
_operations_view.appendChild(_param_div);


_machine_events["cars_g"].style.gridColumn="-1";
_machine_events["cars_g"].innerHTML = "cars_g";
_machine_events["cars_g"].parameterNames = [];
_machine_events["cars_g"].onclick = function() {
  var parameters = {};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_g"] == null ?? true) {
      transition = _machine["_tr_cars_g"]();
      _transition_list[index]["cars_g"] = transition;
  } else {
      transition = _transition_list[index]["cars_g"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_g is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_g!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_g!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_g(...parameters);
    createHistoryElement("cars_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_g", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_g"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_g"].disabled = true;
        }
        createOptionList("cars_g", transition);
    }
    alert(error.message);
  }
}

_operations_view.appendChild(_machine_events["cars_g"]);

_svg_events["cars_green"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_green");
_svg_events["cars_green"].onclick = function() {
  var parameters = {
};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_g"] == null ?? true) {
      transition = _machine["_tr_cars_g"]();
      _transition_list[index]["cars_g"] = transition;
  } else {
      transition = _transition_list[index]["cars_g"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_g is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_g!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_g!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_g(...parameters);
    createHistoryElement("cars_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_g", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_g"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_g"].disabled = true;
        }
        createOptionList("cars_g", transition);
    }
    alert(error.message);
  }
}

_param_div = document.createElement("div");
_param_div.classList.add("param");
_machine_events["peds_g"] = document.createElement("button");
_operations_view.appendChild(_param_div);


_machine_events["peds_g"].style.gridColumn="-1";
_machine_events["peds_g"].innerHTML = "peds_g";
_machine_events["peds_g"].parameterNames = [];
_machine_events["peds_g"].onclick = function() {
  var parameters = {};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["peds_g"] == null ?? true) {
      transition = _machine["_tr_peds_g"]();
      _transition_list[index]["peds_g"] = transition;
  } else {
      transition = _transition_list[index]["peds_g"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event peds_g is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event peds_g!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event peds_g!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.peds_g(...parameters);
    createHistoryElement("peds_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "peds_g", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["peds_g"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["peds_g"].disabled = true;
        }
        createOptionList("peds_g", transition);
    }
    alert(error.message);
  }
}

_operations_view.appendChild(_machine_events["peds_g"]);

_svg_events["peds_green"] = document.getElementById("traffic_light").contentDocument.getElementById("peds_green");
_svg_events["peds_green"].onclick = function() {
  var parameters = {
};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["peds_g"] == null ?? true) {
      transition = _machine["_tr_peds_g"]();
      _transition_list[index]["peds_g"] = transition;
  } else {
      transition = _transition_list[index]["peds_g"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event peds_g is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event peds_g!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event peds_g!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.peds_g(...parameters);
    createHistoryElement("peds_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "peds_g", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["peds_g"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["peds_g"].disabled = true;
        }
        createOptionList("peds_g", transition);
    }
    alert(error.message);
  }
}

_param_div = document.createElement("div");
_param_div.classList.add("param");
_machine_events["cars_y"] = document.createElement("button");
_operations_view.appendChild(_param_div);


_machine_events["cars_y"].style.gridColumn="-1";
_machine_events["cars_y"].innerHTML = "cars_y";
_machine_events["cars_y"].parameterNames = [];
_machine_events["cars_y"].onclick = function() {
  var parameters = {};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_y"] == null ?? true) {
      transition = _machine["_tr_cars_y"]();
      _transition_list[index]["cars_y"] = transition;
  } else {
      transition = _transition_list[index]["cars_y"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_y is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_y!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_y!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_y(...parameters);
    createHistoryElement("cars_y(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_y", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_y"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_y"].disabled = true;
        }
        createOptionList("cars_y", transition);
    }
    alert(error.message);
  }
}

_operations_view.appendChild(_machine_events["cars_y"]);

_svg_events["cars_yellow_2"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_yellow_2");
_svg_events["cars_yellow_2"].onclick = function() {
  var parameters = {
};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_y"] == null ?? true) {
      transition = _machine["_tr_cars_y"]();
      _transition_list[index]["cars_y"] = transition;
  } else {
      transition = _transition_list[index]["cars_y"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_y is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_y!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_y!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_y(...parameters);
    createHistoryElement("cars_y(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_y", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_y"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_y"].disabled = true;
        }
        createOptionList("cars_y", transition);
    }
    alert(error.message);
  }
}

_param_div = document.createElement("div");
_param_div.classList.add("param");
_machine_events["peds_r"] = document.createElement("button");
_operations_view.appendChild(_param_div);


_machine_events["peds_r"].style.gridColumn="-1";
_machine_events["peds_r"].innerHTML = "peds_r";
_machine_events["peds_r"].parameterNames = [];
_machine_events["peds_r"].onclick = function() {
  var parameters = {};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["peds_r"] == null ?? true) {
      transition = _machine["_tr_peds_r"]();
      _transition_list[index]["peds_r"] = transition;
  } else {
      transition = _transition_list[index]["peds_r"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event peds_r is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event peds_r!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event peds_r!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.peds_r(...parameters);
    createHistoryElement("peds_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "peds_r", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["peds_r"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["peds_r"].disabled = true;
        }
        createOptionList("peds_r", transition);
    }
    alert(error.message);
  }
}

_operations_view.appendChild(_machine_events["peds_r"]);

_svg_events["peds_red"] = document.getElementById("traffic_light").contentDocument.getElementById("peds_red");
_svg_events["peds_red"].onclick = function() {
  var parameters = {
};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["peds_r"] == null ?? true) {
      transition = _machine["_tr_peds_r"]();
      _transition_list[index]["peds_r"] = transition;
  } else {
      transition = _transition_list[index]["peds_r"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event peds_r is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event peds_r!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event peds_r!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.peds_r(...parameters);
    createHistoryElement("peds_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "peds_r", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["peds_r"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["peds_r"].disabled = true;
        }
        createOptionList("peds_r", transition);
    }
    alert(error.message);
  }
}

_param_div = document.createElement("div");
_param_div.classList.add("param");
_machine_events["cars_ry"] = document.createElement("button");
_operations_view.appendChild(_param_div);


_machine_events["cars_ry"].style.gridColumn="-1";
_machine_events["cars_ry"].innerHTML = "cars_ry";
_machine_events["cars_ry"].parameterNames = [];
_machine_events["cars_ry"].onclick = function() {
  var parameters = {};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_ry"] == null ?? true) {
      transition = _machine["_tr_cars_ry"]();
      _transition_list[index]["cars_ry"] = transition;
  } else {
      transition = _transition_list[index]["cars_ry"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_ry is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_ry!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_ry!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_ry(...parameters);
    createHistoryElement("cars_ry(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_ry", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_ry"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_ry"].disabled = true;
        }
        createOptionList("cars_ry", transition);
    }
    alert(error.message);
  }
}

_operations_view.appendChild(_machine_events["cars_ry"]);

_svg_events["cars_yellow_1"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_yellow_1");
_svg_events["cars_yellow_1"].onclick = function() {
  var parameters = {
};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_ry"] == null ?? true) {
      transition = _machine["_tr_cars_ry"]();
      _transition_list[index]["cars_ry"] = transition;
  } else {
      transition = _transition_list[index]["cars_ry"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_ry is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_ry!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_ry!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_ry(...parameters);
    createHistoryElement("cars_ry(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_ry", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_ry"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_ry"].disabled = true;
        }
        createOptionList("cars_ry", transition);
    }
    alert(error.message);
  }
}

_param_div = document.createElement("div");
_param_div.classList.add("param");
_machine_events["cars_r"] = document.createElement("button");
_operations_view.appendChild(_param_div);


_machine_events["cars_r"].style.gridColumn="-1";
_machine_events["cars_r"].innerHTML = "cars_r";
_machine_events["cars_r"].parameterNames = [];
_machine_events["cars_r"].onclick = function() {
  var parameters = {};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_r"] == null ?? true) {
      transition = _machine["_tr_cars_r"]();
      _transition_list[index]["cars_r"] = transition;
  } else {
      transition = _transition_list[index]["cars_r"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_r is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_r!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_r!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_r(...parameters);
    createHistoryElement("cars_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_r", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_r"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_r"].disabled = true;
        }
        createOptionList("cars_r", transition);
    }
    alert(error.message);
  }
}

_operations_view.appendChild(_machine_events["cars_r"]);

_svg_events["cars_red"] = document.getElementById("traffic_light").contentDocument.getElementById("cars_red");
_svg_events["cars_red"].onclick = function() {
  var parameters = {
};
  let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
  var transition;
  if(_transition_list[index]?.["cars_r"] == null ?? true) {
      transition = _machine["_tr_cars_r"]();
      _transition_list[index]["cars_r"] = transition;
  } else {
      transition = _transition_list[index]["cars_r"];
  }
  if(!(transition instanceof BSet)) {
    if(!transition) {
        alert("Event cars_r is not enabled!");
        return;
    }
  } else {
    try  {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
    } catch {
        alert("Invalid parameters for event cars_r!\nPossible values are:\n" + transition.toString());
        return;
    }
    if(! transition.elementOf(parameterTuple).booleanValue()) {
        alert("Invalid parameters for event cars_r!\nPossible values are:\n" + transition.toString());
        return;
    }
  }
  try {
    var parameters = [];
    var returnValue = _machine.cars_r(...parameters);
    createHistoryElement("cars_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
    let parametersJSON = {};
    _current_trace = _current_trace.slice(0, index + 1)
    _current_trace.push({name: "cars_r", params: parametersJSON});
    updateVisuals();
  } catch (error) {
    if(! error instanceof SelectError) {
        throw error;
    }
    if(transition instanceof BSet) {
        var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
        transition = transition.difference(new BSet(parameterTuple));
        _transition_list[index]["cars_r"] = transition;
        if(transition.size().intValue() == 0) {
            _machine_events["cars_r"].disabled = true;
        }
        createOptionList("cars_r", transition);
    }
    alert(error.message);
  }
}



updateVisuals();
if(_operations_view.querySelectorAll("label").length == 0) {
    document.documentElement.style.setProperty('--noneOrGrid', 'none');
}

function displayTrace(trace) {
    selectHistoryElement(-_history_view.querySelector(".active").index);
    let transitions = trace.transitionList
    for(let transition of transitions) {
      if(transition.name.startsWith("$")) {
        continue;
      }
      if(transition.params == null) {
        transition.params = {};
      }
      let parameters = Object.keys(transition.params).map(param => _machine_events[transition.name][param].parseValue(transition.params[param]))
      let returnValue = _machine[transition.name](...parameters);
      createHistoryElement(transition.name + "(" + parameters.join(", ") + ")" + (returnValue? " (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
      let parametersJSON = transition.params;
      _current_trace.push({name: transition.name, params: parametersJSON});
    }
    updateVisuals();
    selectHistoryElement(_history_view.querySelector("span:last-of-type").index-_history_view.querySelector(".active").index);
}

function importTrace() {
    var _file_input = document.querySelector("#_upload_trace_input");
    _file_input.accept = ".prob2trace";

    _file_input.onchange = async _ => {
        let files = Array.from(_file_input.files);
        let file = files[0];
        let response = await fetch(file.name);
        let data = await response.text();
        let trace = JSON.parse(data);
        createScenarioElement(file.name, trace);

        try {
            displayTrace(trace);
        } catch (error) {
            alert("Trace could not be completely imported.");
            console.error(error);
        }
    };

    _file_input.click();
}

function exportTrace() {
  var transitions = _current_trace;
  var object = {
    description: "Created from B2Program JS Export",
    transitionList: transitions,
    metadata: {
      fileType: "Trace",
      formatVersion: 1,
      creator: "B2Program JS",
      modelName: "TrafficLight"
    }
  };
  const blob = new Blob([JSON.stringify(object, null, '\t')]);
  const a = document.createElement('a');
  a.href = URL.createObjectURL(blob);
  a.download = 'Scenario.prob2trace';
  a.click();
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function runTrace(ms) {
    let firstElement = _history_view.querySelector("span");
    firstElement.click();
    let currentHistoryElement = _history_view.querySelector(".active");
    let index = currentHistoryElement.index + 1;
    while (index >= 0 && index < _state_list.length) {
      selectHistoryElement(1);
      await sleep(ms);
      currentHistoryElement = _history_view.querySelector(".active");
      index = currentHistoryElement.index + 1;
    }
}