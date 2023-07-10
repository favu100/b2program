import TrafficLight from "./TrafficLight.js";
import {SelectError} from "./btypes/BUtils.js";
import {enum_colors} from "./TrafficLight.js"
import {colors} from "./TrafficLight.js"
import {BTuple} from "./btypes/BTuple.js";
import {BSet} from "./btypes/BSet.js";
import {BBoolean} from "./btypes/BBoolean.js";
import {BObject} from "./btypes/BObject.js";
import {BString} from "./btypes/BString.js";

import {Activation} from "./simulation/Activation.js";
import {ActivationKind} from "./simulation/ActivationKind.js";

document.addEventListener('DOMContentLoaded', (event) => {
  checkLoaded();
});

function checkLoaded() {
    const iframe = document.getElementById("traffic_light");
    if (iframe == null) {
        window.setTimeout(checkLoaded, 100);
    } else {
        var iframeDoc = iframe.contentDocument;
        if (iframeDoc != null && iframeDoc.readyState == 'complete') {
            initialize();
        } else {
            window.setTimeout(checkLoaded, 100);
        }
    }
}

function initialize() {
    var _machine = new TrafficLight();
    var _state_list = [];
    var _transition_list = [];
    var _description_list = [];
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
      if(document.querySelector(".active") != null) {
        descriptionText.innerHTML = _description_list[document.querySelector(".active").index];
      }
    }

    var _history_view_buttons = document.getElementById("_history_view_buttons");
    var _buttonLeft = document.createElement("button");
    var _buttonRight = document.createElement("button");
    var _buttonUpload = document.createElement("button");
    var _buttonExport = document.createElement("button");
    var _inputUpload = document.createElement("input");
    var _buttonRun10 = document.createElement("button");
    var _buttonRun500 = document.createElement("button");

    var _simulation_view_buttons = document.getElementById("_simulation_view_buttons");
    var _buttonLoadSimulation = document.createElement("button");
    var _buttonExportTimedTrace = document.createElement("button");


    function flattenTuple(tuple) {
        if(!(tuple instanceof BTuple)) {
            return [tuple];
        }
        return [...flattenTuple(tuple.projection1()), tuple.projection2()];
    }

    function unflattenTuple(arr) {
        if(arr.length == 1) {
            return arr[0];
        }
        let last = arr.pop();
        let tuple = last;

        for (let i = arr.length - 2; i >= 0; i--) {
          tuple = new BTuple(arr[i], tuple);
        }

        return tuple;
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
    _simulation_view = document.getElementById("_simulation_view");

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
      _description_list = _description_list.slice(0, index);
      _description_list.push("");
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

    function createSimulationElement(text, simulation) {
      var simulation_element = document.createElement("button");
      var remove_element = document.createElement("button");
      simulation_element.innerHTML = text + "</br>";
      remove_element.innerHTML = "X";
      var div_element = document.createElement("div");
      div_element.appendChild(simulation_element);
      div_element.appendChild(remove_element);
      _simulation_view.appendChild(div_element);
      simulation_element.onclick = function() {
        try {
            playSimulation(simulation);
        } catch (error) {
            alert("Simulation could not be played.");
            console.error(error);
        }
      };
      remove_element.onclick = function() {
        _simulation_view.removeChild(div_element);
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

    let isEditing = false;

    btEditDescription = document.getElementById("btEditDescription");
    descriptionText = document.getElementById("descriptionText");
    taDescription = document.getElementById("taDescription");

    btEditDescription.onclick = function() {
        if(isEditing) {
            btEditDescription.textContent = "Edit";
            descriptionText.removeAttribute("hidden");
            taDescription.setAttribute("hidden", "hidden");
            descriptionText.textContent = taDescription.value;
            _description_list[document.querySelector(".active").index] = taDescription.value;
        } else {
            btEditDescription.textContent = "Apply";
            descriptionText.setAttribute("hidden", "hidden");
            taDescription.removeAttribute("hidden");
            taDescription.value = descriptionText.textContent;
        }
        isEditing = !isEditing;
    };



    _buttonLoadSimulation.textContent = "Load Simulation";
    _buttonLoadSimulation.onclick = loadSimulation;
    _simulation_view_buttons.appendChild(_buttonLoadSimulation);

    _buttonExportTimedTrace.textContent = "Export Timed Trace"
    _buttonExportTimedTrace.onclick = exportTimedTrace;
    _simulation_view_buttons.appendChild(_buttonExportTimedTrace);

    var _param_div;
    var _param_datalist;
    var _onclick_function;
    var _machine_events = {};
    var _svg_events = {};
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_r(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_r", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_r");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_r(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_r", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_r");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_g(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_g", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_g");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_g(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_g", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_g");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.peds_r(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("peds_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "peds_r", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("peds_r");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.peds_r(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("peds_r(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "peds_r", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("peds_r");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_ry(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_ry(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_ry", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_ry");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_ry(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_ry(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_ry", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_ry");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.peds_g(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("peds_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "peds_g", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("peds_g");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.peds_g(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("peds_g(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "peds_g", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("peds_g");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_y(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_y(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_y", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_y");
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
      }
      try {
        var parameters = [];
        var returnValue = _machine.cars_y(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("cars_y(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "cars_y", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("cars_y");
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


    updateVisuals();
    if(_operations_view.querySelectorAll("label").length == 0) {
        document.documentElement.style.setProperty('--noneOrGrid', 'none');
    }

    function displayTrace(trace) {
        selectHistoryElement(-_history_view.querySelector(".active").index);
        let transitions = trace.transitionList
        _description_list = [];
        for(let transition of transitions) {
          _description_list.push(transition.description == null ? "" : transition.description);
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
      let i = 0;
      for(let transition of transitions) {
        transition.description = _description_list[i];
        i++;
      }
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

    function loadSimulation() {
        var _file_input = document.querySelector("#_load_simulation");
        _file_input.accept = ".json";
        _file_input.onchange = async _ => {
            let files = Array.from(_file_input.files);
            let file = files[0];
            let response = await fetch(file.name);
            let data = await response.text();
            let simulation = JSON.parse(data);
            createSimulationElement(file.name, simulation);
        };

        _file_input.click();
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

    let activationConfigurationsSorted = new Array();
    let noActivationQueued = false;
    let realTime = 0;
    let time = 0;
    let delay = 0;
    let configurationToActivation = {};
    let activationConfigurationMap = {};
    let timestamps = new Array();
    let operationToActivations = {};
    let listeners = [];
    let newDelay = 0;
    let thread = 0;

    async function playSimulation(simulation) {
        _machine = new TrafficLight();
        activationConfigurationsSorted = new Array();
        noActivationQueued = false;
        realTime = 0;
        time = 0;
        delay = 0;
        configurationToActivation = {};
        activationConfigurationMap = {};
        timestamps = new Array();
        operationToActivations = {};
        createHistoryElement("Initialisation", 0);
        updateVisuals();
        startTimer();

        // initialize
        thread = thread + 1;
        let currentThread = thread;
        listeners = simulation["listeners"];


        for(let config of simulation["activations"]) {
            let id = config["id"];
            let opName = config["execute"];
            if(opName != null) {
                activationConfigurationsSorted.push(config)
                if(operationToActivations[opName] == null) {
                    operationToActivations[opName] = new Set();
                }
                operationToActivations[opName].add(id);
                configurationToActivation[id] = new Array();
            }
            activationConfigurationMap[id] = config;
        }

        activationConfigurationsSorted.sort((act1, act2) => act1["priority"] == null ? false : act2["priority"] == null ? true : act1["priority"] - act2["priority"]);

        if(Object.keys(configurationToActivation).includes("$setup_constants")) {
            let activation = activationConfigurationMap["$setup_constants"];
            activateEvent(activation, new Array(), "1=1");
        }

        if(Object.keys(configurationToActivation).includes("$initialise_machine")) {
            let activation = activationConfigurationMap["$initialise_machine"];
            activateEvent(activation, new Array(), "1=1");
        }

        timestamps.push(0);

        while(true) { // Finish at ending condition
            updateRemainingTime();
            executeActivatedEvents(); // Execute activated events
            updateDelay();
            updateVisuals();
            await sleep(delay);
            if(currentThread != thread) {
                break;
            }
        }
    }

    function startTimer() {
        let timer = setInterval(function() {
          realTime = realTime + 100;
        }, 100);
    }


    function executeActivatedEvents() {
        for(let opConfig of activationConfigurationsSorted) {
            if (endingConditionReached()) {
                break;
            }
            executeActivatedEvent(opConfig);
        }
    }

    function executeActivatedEvent(opConfig) {
        let id = opConfig["id"];
        let activationConfiguration = opConfig["activating"];
        if(typeof activationConfiguration === 'string') {
            activationConfiguration = [activationConfiguration];
        }

		let activationForOperation = configurationToActivation[id];
		let activationForOperationCopy = [...activationForOperation];

        let index = 0;
		for(let activation of activationForOperationCopy) {
			// select operation only if its time is 0
			if(activation.getTime() > 0) {
				break;
			}
            activationForOperation.splice(index, 1);
			let executed = executeTransition(activation);
			if(executed) {
                activateEvents(activationConfiguration, new Array(), "1=1");
                timestamps.push(time);
            }
			index = index + 1;
		}
    }

    function executeTransition(activation) {
        if("$setup_constants" === activation.getOperation() || "$initialise_machine" === activation.getOperation()) {
            return true;
        }
        let transition = _machine["_tr_" + activation.getOperation()]();
        if(!(transition instanceof BSet)) {
            if(transition) {
                _machine[activation.getOperation()]();
                let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
                createHistoryElement(activation.getOperation() + "()", _history_view.querySelector(".active").index + 1);
                _current_trace = _current_trace.slice(0, index + 1)
                _current_trace.push({name: activation.getOperation(), params: {}});
                return true;
            }
        } else if(transition.size().intValue() > 0) {
            let fixedVariables = activation.getFixedVariables();
            let parameters = [];
            let chosen = false;
            if(fixedVariables == null || "first" == fixedVariables) {
                for(let trans of transition) {
                    parameters = flattenTuple(trans);
                    break;
                }
                chosen = true;
            } else if("uniform" == fixedVariables) {
                parameters = flattenTuple(transition.nondeterminism());
                chosen = true;
            } else {
                for(let key of Object.keys(fixedVariables)) {
                    parameters.push(_machine_events[activation.getOperation()][key].parseValue(fixedVariables[key]));
                }
                chosen = false;
            }
            let parameterAsExpression = unflattenTuple(parameters);
            if(chosen || transition.elementOf(parameterAsExpression).booleanValue()) {
                _machine[activation.getOperation()](...parameters);
                let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
                createHistoryElement(activation.getOperation(), _history_view.querySelector(".active").index + 1);
                _current_trace = _current_trace.slice(0, index + 1)
                _current_trace.push({name: activation.getOperation(), params: {}});
                return true;
            }
        }
        return false;
    }

    function updateRemainingTime() {
        if(noActivationQueued) {
            time = realTime;
        } else {
            time += delay;
        }
        for (let key in configurationToActivation) {
            for (let i = 0; i < configurationToActivation[key].length; i++) {
                let activation = configurationToActivation[key][i];
                activation.decreaseTime(delay);
            }
        }
    }

    function updateDelay() {
        noActivationQueued = true;
        let newDelay = Number.MAX_SAFE_INTEGER;
        for (let key in configurationToActivation) {
            for (let i = 0; i < configurationToActivation[key].length; i++) {
                let activation = configurationToActivation[key][i];
                noActivationQueued = false;
                if (activation.getTime() < newDelay) {
                    newDelay = activation.getTime();
                }
            }
        }
        delay = newDelay;
    }


    function endingConditionReached() {
        return noActivationQueued && (listeners == null || listeners.size == 0);
    }

    function activateEvents(activation, parametersAsString, parameterPredicates) {
        if(activation != null) {
            for(let activationConfiguration of activation) {
                handleEventConfiguration(activationConfigurationMap[activationConfiguration], parametersAsString, parameterPredicates);
            }
        }
    }

    function handleEventConfiguration(activationConfiguration, parametersAsString, parameterPredicates) {
        if(activationConfiguration["execute"] != null) {
            activateEvent(activationConfiguration, parametersAsString, parameterPredicates);
        } else if(activationConfiguration["chooseActivation"] != null) {
            chooseEvent(activationConfiguration, parametersAsString, parameterPredicates);
        }
    }

    function chooseEvent(activationChoiceConfiguration, parametersAsString, parameterPredicates) {
        let probabilityMinimum = 0.0;
        let randomDouble = Math.random();
        for (const id of Object.keys(activationChoiceConfiguration["chooseActivation"])) {
          let activationConfiguration = activationConfigurationMap[id];
          let evalProbability = parseFloat(activationChoiceConfiguration["chooseActivation"][id]);
          if (randomDouble > probabilityMinimum && randomDouble < probabilityMinimum + evalProbability) {
            handleEventConfiguration(activationConfiguration, parametersAsString, parameterPredicates);
          }
          probabilityMinimum += evalProbability;
        }
        if (Math.abs(1.0 - probabilityMinimum) > 0.000001) {
          throw new Error("Sum of probabilistic choice is not equal 1");
        }

    }

    function activateEvent(activationOperationConfiguration, parametersAsString, parameterPredicates) {
        let activationsForId = configurationToActivation[activationOperationConfiguration["id"]];
        if (!activationsForId) {
          return;
        }
        let id = activationOperationConfiguration["id"];
        let opName = activationOperationConfiguration["execute"];
        let time = activationOperationConfiguration["after"];
        let activationKind = activationOperationConfiguration["activationKind"];
        let additionalGuards = activationOperationConfiguration["additionalGuards"];
        let parameters = activationOperationConfiguration["fixedVariables"];
        let probability = activationOperationConfiguration["probabilisticVariables"];
        let evaluatedTime = parseInt(time);

        switch (activationKind) {
          case 'SINGLE':
          case 'SINGLE_MAX':
          case 'SINGLE_MIN':
            activateSingleOperations(id, activationKind, new Activation(opName, evaluatedTime, additionalGuards, activationKind, parameters, probability, parametersAsString, parameterPredicates));
            break;
          case 'MULTI':
          default:
            activateMultiOperations(activationsForId, new Activation(opName, evaluatedTime, additionalGuards, activationKind, parameters, probability, parametersAsString, parameterPredicates));
            break;
        }
    }

    function activateMultiOperations(activationsForOperation, activation) {
      let insertionIndex = 0;
      while (insertionIndex < activationsForOperation.length && activation.time >= activationsForOperation[insertionIndex].time) {
        insertionIndex++;
      }
      activationsForOperation.splice(insertionIndex, 0, activation);
    }

    function activateSingleOperations(id, activationKind, activation) {
      let evaluatedTime = activation.time;

      let activationsForId = configurationToActivation[id];
      if (activationsForId.length > 0) {
        switch (activationKind) {
          case 'SINGLE_MIN': {
            let activationForId = activationsForId[0];
            let otherActivationTime = activationForId.time;
            if (evaluatedTime < otherActivationTime) {
              activationsForId.splice(0, activationsForId.length, activation);
            }
            return;
          }
          case 'SINGLE_MAX': {
            let activationForId = activationsForId[0];
            let otherActivationTime = activationForId.time;
            if (evaluatedTime > otherActivationTime) {
              activationsForId.splice(0, activationsForId.length, activation);
            }
            return;
          }
          case 'SINGLE':
            return;
          default:
            break;
        }
      }

      configurationToActivation[id].push(activation);
    }

    function exportTimedTrace() {
      let transitions = _current_trace;
      let i = 0;
      let activations = [];
      for(let transition of transitions) {
        let afterTime = i == 0 ? 0 : timestamps[i] - timestamps[i-1];
        let operation = transition["name"];
        let id = operation + (operation.startsWith("$") ? "" : "_" + i);
        let activating = transitions[i+1] == null ? null : (transitions[i+1]["name"] + "_" + (i+1));
        let activation = {
            "id": id,
            "execute": operation,
            "after": afterTime,
            "priority": 0,
            "fixedVariables": transition["parameters"],
            "activating": activating
        };
        activations.push(activation);
        i++;
      }
      var object = {
        activations : activations,
        listeners : [],
        metadata: {
          fileType: "Timed Trace",
          creator: "B2Program JS",
          modelName: "TrafficLight"
        }
      };
      const blob = new Blob([JSON.stringify(object, null, '\t')]);
      const a = document.createElement('a');
      a.href = URL.createObjectURL(blob);
      a.download = 'Timed_Trace.json';
      a.click();
    }

    function triggerSimulationOnInteraction(opName) {
        if(listeners == null) {
            return;
        }
        for(let listener of listeners) {
            if(listener["event"] === opName) {
                let activating;
                if(typeof listener["activating"] === 'string') {
                    activating = [listener["activating"]];
                } else {
                    activating = listener["activating"];
                }
                for(let activation of activating) {
                    let activationConfiguration = activationConfigurationMap[activation];
                    activateEvent(activationConfiguration, new Array(), "1=1");
                }
            }
        }
        timestamps.push(realTime);
    }

}