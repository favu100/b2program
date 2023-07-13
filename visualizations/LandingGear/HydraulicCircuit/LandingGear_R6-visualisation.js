import LandingGear_R6 from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js";
import {SelectError} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BUtils.js";
import {enum_DOOR_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {DOOR_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {enum_GEAR_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {GEAR_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {enum_HANDLE_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {HANDLE_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {enum_POSITION} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {POSITION} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {enum_VALVE_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {VALVE_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {enum_SWITCH_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {SWITCH_STATE} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/LandingGear_R6.js"
import {BTuple} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BTuple.js";
import {BSet} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BSet.js";
import {BRelation} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BRelation.js";
import {BInteger} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BInteger.js";
import {BBoolean} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BBoolean.js";
import {BObject} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BObject.js";
import {BString} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/btypes/BString.js";

import {Activation} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/simulation/Activation.js";
import {ActivationKind} from "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit/simulation/ActivationKind.js";

document.addEventListener('DOMContentLoaded', (event) => {
  checkLoaded();
});

function checkLoaded() {
    const iframe = document.getElementById("architecture");
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
    var _machine = new LandingGear_R6();
    var _state_list = [];
    var _transition_list = [];
    var _description_list = [];
    var _included_machines = {};
    _included_machines["LandingGear_R6"] = function(){return _machine};
    var _state_view_vars = document.getElementById("_state_view_variables");
    var _state_view_consts = document.getElementById("_state_view_constants");
    var _state_view_sets = document.getElementById("_state_view_sets");
    var _state_view_invariant = document.getElementById("_state_view_invariant");
    var _svg_vars = {}
        _svg_vars["retraction_circuit_doors_1"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_doors_1")
        _svg_vars["fr_gear_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("fr_gear_cylinder_forcer")
        _svg_vars["retraction_circuit_doors_3"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_doors_3")
        _svg_vars["retraction_circuit_doors_2"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_doors_2")
        _svg_vars["retraction_circuit_doors_4"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_doors_4")
        _svg_vars["eo_retract_gears_2"] = document.getElementById("architecture").contentDocument.getElementById("eo_retract_gears_2")
        _svg_vars["eo_retract_gears_1"] = document.getElementById("architecture").contentDocument.getElementById("eo_retract_gears_1")
        _svg_vars["lt_gear_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("lt_gear_cylinder_forcer")
        _svg_vars["eo_close_doors_2"] = document.getElementById("architecture").contentDocument.getElementById("eo_close_doors_2")
        _svg_vars["ev_retraction_gears_2"] = document.getElementById("architecture").contentDocument.getElementById("ev_retraction_gears_2")
        _svg_vars["ev_retraction_gears_1"] = document.getElementById("architecture").contentDocument.getElementById("ev_retraction_gears_1")
        _svg_vars["lt_door_cylinder_r"] = document.getElementById("architecture").contentDocument.getElementById("lt_door_cylinder_r")
        _svg_vars["fr_door_cylinder_l"] = document.getElementById("architecture").contentDocument.getElementById("fr_door_cylinder_l")
        _svg_vars["lt_gear_cylinder_l"] = document.getElementById("architecture").contentDocument.getElementById("lt_gear_cylinder_l")
        _svg_vars["door_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("door_cylinder_forcer")
        _svg_vars["fr_door_cylinder_r"] = document.getElementById("architecture").contentDocument.getElementById("fr_door_cylinder_r")
        _svg_vars["eo_close_doors_1"] = document.getElementById("architecture").contentDocument.getElementById("eo_close_doors_1")
        _svg_vars["rt_gear_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("rt_gear_cylinder_forcer")
        _svg_vars["eo_extend_gears_1"] = document.getElementById("architecture").contentDocument.getElementById("eo_extend_gears_1")
        _svg_vars["ev_extended_gears_1"] = document.getElementById("architecture").contentDocument.getElementById("ev_extended_gears_1")
        _svg_vars["eo_extend_gears_2"] = document.getElementById("architecture").contentDocument.getElementById("eo_extend_gears_2")
        _svg_vars["rt_door_cylinder_r"] = document.getElementById("architecture").contentDocument.getElementById("rt_door_cylinder_r")
        _svg_vars["ev_extended_gears_2"] = document.getElementById("architecture").contentDocument.getElementById("ev_extended_gears_2")
        _svg_vars["analogical_switch_closed"] = document.getElementById("architecture").contentDocument.getElementById("analogical_switch_closed")
        _svg_vars["rt_door_cylinder_l"] = document.getElementById("architecture").contentDocument.getElementById("rt_door_cylinder_l")
        _svg_vars["hydraulic_circuit_5"] = document.getElementById("architecture").contentDocument.getElementById("hydraulic_circuit_5")
        _svg_vars["hydraulic_circuit_4"] = document.getElementById("architecture").contentDocument.getElementById("hydraulic_circuit_4")
        _svg_vars["hydraulic_circuit_3"] = document.getElementById("architecture").contentDocument.getElementById("hydraulic_circuit_3")
        _svg_vars["ev_handle"] = document.getElementById("architecture").contentDocument.getElementById("ev_handle")
        _svg_vars["ev_open_doors_2"] = document.getElementById("architecture").contentDocument.getElementById("ev_open_doors_2")
        _svg_vars["hydraulic_circuit_2"] = document.getElementById("architecture").contentDocument.getElementById("hydraulic_circuit_2")
        _svg_vars["ev_open_doors_1"] = document.getElementById("architecture").contentDocument.getElementById("ev_open_doors_1")
        _svg_vars["hydraulic_circuit_6"] = document.getElementById("architecture").contentDocument.getElementById("hydraulic_circuit_6")
        _svg_vars["extension_circuit_doors_3"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_doors_3")
        _svg_vars["ev_general_1"] = document.getElementById("architecture").contentDocument.getElementById("ev_general_1")
        _svg_vars["extension_circuit_doors_2"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_doors_2")
        _svg_vars["rt_door_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("rt_door_cylinder_forcer")
        _svg_vars["ev_general_2"] = document.getElementById("architecture").contentDocument.getElementById("ev_general_2")
        _svg_vars["extension_circuit_doors_1"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_doors_1")
        _svg_vars["hydraulic_circuit_1"] = document.getElementById("architecture").contentDocument.getElementById("hydraulic_circuit_1")
        _svg_vars["close_switch_1"] = document.getElementById("architecture").contentDocument.getElementById("close_switch_1")
        _svg_vars["close_switch_2"] = document.getElementById("architecture").contentDocument.getElementById("close_switch_2")
        _svg_vars["extension_circuit_doors_4"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_doors_4")
        _svg_vars["close_switch_3"] = document.getElementById("architecture").contentDocument.getElementById("close_switch_3")
        _svg_vars["analogical_switch_1"] = document.getElementById("architecture").contentDocument.getElementById("analogical_switch_1")
        _svg_vars["analogical_switch_2"] = document.getElementById("architecture").contentDocument.getElementById("analogical_switch_2")
        _svg_vars["analogical_switch_3"] = document.getElementById("architecture").contentDocument.getElementById("analogical_switch_3")
        _svg_vars["eo_general_3"] = document.getElementById("architecture").contentDocument.getElementById("eo_general_3")
        _svg_vars["lt_door_cylinder_l"] = document.getElementById("architecture").contentDocument.getElementById("lt_door_cylinder_l")
        _svg_vars["eo_general_2"] = document.getElementById("architecture").contentDocument.getElementById("eo_general_2")
        _svg_vars["lt_gear_cylinder_r"] = document.getElementById("architecture").contentDocument.getElementById("lt_gear_cylinder_r")
        _svg_vars["eo_general_1"] = document.getElementById("architecture").contentDocument.getElementById("eo_general_1")
        _svg_vars["ev_close_doors_1"] = document.getElementById("architecture").contentDocument.getElementById("ev_close_doors_1")
        _svg_vars["ev_close_doors_2"] = document.getElementById("architecture").contentDocument.getElementById("ev_close_doors_2")
        _svg_vars["fr_gear_cylinder_l"] = document.getElementById("architecture").contentDocument.getElementById("fr_gear_cylinder_l")
        _svg_vars["fr_gear_cylinder_r"] = document.getElementById("architecture").contentDocument.getElementById("fr_gear_cylinder_r")
        _svg_vars["retraction_circuit_gears_3"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_gears_3")
        _svg_vars["retraction_circuit_gears_4"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_gears_4")
        _svg_vars["analogical_switch_open"] = document.getElementById("architecture").contentDocument.getElementById("analogical_switch_open")
        _svg_vars["retraction_circuit_gears_1"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_gears_1")
        _svg_vars["retraction_circuit_gears_2"] = document.getElementById("architecture").contentDocument.getElementById("retraction_circuit_gears_2")
        _svg_vars["extension_circuit_gears_1"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_gears_1")
        _svg_vars["extension_circuit_gears_2"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_gears_2")
        _svg_vars["extension_circuit_gears_3"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_gears_3")
        _svg_vars["lt_door_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("lt_door_cylinder_forcer")
        _svg_vars["eo_open_doors_2"] = document.getElementById("architecture").contentDocument.getElementById("eo_open_doors_2")
        _svg_vars["extension_circuit_gears_4"] = document.getElementById("architecture").contentDocument.getElementById("extension_circuit_gears_4")
        _svg_vars["rt_gear_cylinder_r"] = document.getElementById("architecture").contentDocument.getElementById("rt_gear_cylinder_r")
        _svg_vars["eo_open_doors_1"] = document.getElementById("architecture").contentDocument.getElementById("eo_open_doors_1")
        _svg_vars["rt_gear_cylinder_l"] = document.getElementById("architecture").contentDocument.getElementById("rt_gear_cylinder_l")
        _svg_vars["fr_door_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("fr_door_cylinder_forcer")
        _svg_vars["gear_cylinder_forcer"] = document.getElementById("architecture").contentDocument.getElementById("gear_cylinder_forcer")
    var _machine_vars = {}
    var _var_label;
    var _var_div;
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_analogical_switch();
    _var_div.id = "_var_analogical_switch";
    _machine_vars["analogical_switch"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_analogical_switch";
    _var_label.innerHTML = "LandingGear_R6.analogical_switch";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_general_EV();
    _var_div.id = "_var_general_EV";
    _machine_vars["general_EV"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_general_EV";
    _var_label.innerHTML = "LandingGear_R6.general_EV";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_general_valve();
    _var_div.id = "_var_general_valve";
    _machine_vars["general_valve"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_general_valve";
    _var_label.innerHTML = "LandingGear_R6.general_valve";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_handle_move();
    _var_div.id = "_var_handle_move";
    _machine_vars["handle_move"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_handle_move";
    _var_label.innerHTML = "LandingGear_R6.handle_move";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_close_EV();
    _var_div.id = "_var_close_EV";
    _machine_vars["close_EV"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_close_EV";
    _var_label.innerHTML = "LandingGear_R6.close_EV";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_extend_EV();
    _var_div.id = "_var_extend_EV";
    _machine_vars["extend_EV"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_extend_EV";
    _var_label.innerHTML = "LandingGear_R6.extend_EV";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_open_EV();
    _var_div.id = "_var_open_EV";
    _machine_vars["open_EV"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_open_EV";
    _var_label.innerHTML = "LandingGear_R6.open_EV";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_retract_EV();
    _var_div.id = "_var_retract_EV";
    _machine_vars["retract_EV"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_retract_EV";
    _var_label.innerHTML = "LandingGear_R6.retract_EV";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_shock_absorber();
    _var_div.id = "_var_shock_absorber";
    _machine_vars["shock_absorber"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_shock_absorber";
    _var_label.innerHTML = "LandingGear_R6.shock_absorber";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_valve_close_door();
    _var_div.id = "_var_valve_close_door";
    _machine_vars["valve_close_door"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_valve_close_door";
    _var_label.innerHTML = "LandingGear_R6.valve_close_door";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_valve_extend_gear();
    _var_div.id = "_var_valve_extend_gear";
    _machine_vars["valve_extend_gear"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_valve_extend_gear";
    _var_label.innerHTML = "LandingGear_R6.valve_extend_gear";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_valve_open_door();
    _var_div.id = "_var_valve_open_door";
    _machine_vars["valve_open_door"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_valve_open_door";
    _var_label.innerHTML = "LandingGear_R6.valve_open_door";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_valve_retract_gear();
    _var_div.id = "_var_valve_retract_gear";
    _machine_vars["valve_retract_gear"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_valve_retract_gear";
    _var_label.innerHTML = "LandingGear_R6.valve_retract_gear";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_doors();
    _var_div.id = "_var_doors";
    _machine_vars["doors"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_doors";
    _var_label.innerHTML = "LandingGear_R6.doors";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_gears();
    _var_div.id = "_var_gears";
    _machine_vars["gears"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_gears";
    _var_label.innerHTML = "LandingGear_R6.gears";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_handle();
    _var_div.id = "_var_handle";
    _machine_vars["handle"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_handle";
    _var_label.innerHTML = "LandingGear_R6.handle";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_door();
    _var_div.id = "_var_door";
    _machine_vars["door"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_door";
    _var_label.innerHTML = "LandingGear_R6.door";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get_gear();
    _var_div.id = "_var_gear";
    _machine_vars["gear"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_gear";
    _var_label.innerHTML = "LandingGear_R6.gear";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__DOOR_STATE();
    _var_div.id = "_var_DOOR_STATE";
    _machine_vars["DOOR_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_DOOR_STATE";
    _var_label.innerHTML = "LandingGear_R6.DOOR_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__GEAR_STATE();
    _var_div.id = "_var_GEAR_STATE";
    _machine_vars["GEAR_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_GEAR_STATE";
    _var_label.innerHTML = "LandingGear_R6.GEAR_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__HANDLE_STATE();
    _var_div.id = "_var_HANDLE_STATE";
    _machine_vars["HANDLE_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_HANDLE_STATE";
    _var_label.innerHTML = "LandingGear_R6.HANDLE_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__POSITION();
    _var_div.id = "_var_POSITION";
    _machine_vars["POSITION"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_POSITION";
    _var_label.innerHTML = "LandingGear_R6.POSITION";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__SWITCH_STATE();
    _var_div.id = "_var_SWITCH_STATE";
    _machine_vars["SWITCH_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_SWITCH_STATE";
    _var_label.innerHTML = "LandingGear_R6.SWITCH_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__PLANE_STATE();
    _var_div.id = "_var_PLANE_STATE";
    _machine_vars["PLANE_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_PLANE_STATE";
    _var_label.innerHTML = "LandingGear_R6.PLANE_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._get__VALVE_STATE();
    _var_div.id = "_var_VALVE_STATE";
    _machine_vars["VALVE_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_VALVE_STATE";
    _var_label.innerHTML = "LandingGear_R6.VALVE_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_1();
    _var_div.id = "_check_inv_1";
    _machine_vars["_check_inv_1"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_1";
    _var_label.innerHTML = "analogical_switch:SWITCH_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_2();
    _var_div.id = "_check_inv_2";
    _machine_vars["_check_inv_2"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_2";
    _var_label.innerHTML = "general_EV:BOOL";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_3();
    _var_div.id = "_check_inv_3";
    _machine_vars["_check_inv_3"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_3";
    _var_label.innerHTML = "general_valve:VALVE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_4();
    _var_div.id = "_check_inv_4";
    _machine_vars["_check_inv_4"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_4";
    _var_label.innerHTML = "handle_move:BOOL";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_5();
    _var_div.id = "_check_inv_5";
    _machine_vars["_check_inv_5"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_5";
    _var_label.innerHTML = "close_EV:BOOL";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_6();
    _var_div.id = "_check_inv_6";
    _machine_vars["_check_inv_6"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_6";
    _var_label.innerHTML = "extend_EV:BOOL";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_7();
    _var_div.id = "_check_inv_7";
    _machine_vars["_check_inv_7"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_7";
    _var_label.innerHTML = "open_EV:BOOL";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_8();
    _var_div.id = "_check_inv_8";
    _machine_vars["_check_inv_8"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_8";
    _var_label.innerHTML = "retract_EV:BOOL";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_9();
    _var_div.id = "_check_inv_9";
    _machine_vars["_check_inv_9"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_9";
    _var_label.innerHTML = "shock_absorber:PLANE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_10();
    _var_div.id = "_check_inv_10";
    _machine_vars["_check_inv_10"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_10";
    _var_label.innerHTML = "valve_close_door:VALVE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_11();
    _var_div.id = "_check_inv_11";
    _machine_vars["_check_inv_11"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_11";
    _var_label.innerHTML = "valve_extend_gear:VALVE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_12();
    _var_div.id = "_check_inv_12";
    _machine_vars["_check_inv_12"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_12";
    _var_label.innerHTML = "valve_open_door:VALVE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_13();
    _var_div.id = "_check_inv_13";
    _machine_vars["_check_inv_13"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_13";
    _var_label.innerHTML = "valve_retract_gear:VALVE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_14();
    _var_div.id = "_check_inv_14";
    _machine_vars["_check_inv_14"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_14";
    _var_label.innerHTML = "handle:HANDLE_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_15();
    _var_div.id = "_check_inv_15";
    _machine_vars["_check_inv_15"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_15";
    _var_label.innerHTML = "door:DOOR_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_16();
    _var_div.id = "_check_inv_16";
    _machine_vars["_check_inv_16"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_16";
    _var_label.innerHTML = "gear:GEAR_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_17();
    _var_div.id = "_check_inv_17";
    _machine_vars["_check_inv_17"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_17";
    _var_label.innerHTML = "(open_EV=TRUEorclose_EV=TRUEorretract_EV=TRUEorextend_EV=TRUE)=>general_EV=TRUE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_18();
    _var_div.id = "_check_inv_18";
    _machine_vars["_check_inv_18"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_18";
    _var_label.innerHTML = "not(open_EV=TRUE&close_EV=TRUE)";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_19();
    _var_div.id = "_check_inv_19";
    _machine_vars["_check_inv_19"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_19";
    _var_label.innerHTML = "gears:POSITION-->GEAR_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_20();
    _var_div.id = "_check_inv_20";
    _machine_vars["_check_inv_20"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_20";
    _var_label.innerHTML = "doors:POSITION-->DOOR_STATE";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_21();
    _var_div.id = "_check_inv_21";
    _machine_vars["_check_inv_21"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_21";
    _var_label.innerHTML = "door=closed<=>ran(doors)={closed}";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_22();
    _var_div.id = "_check_inv_22";
    _machine_vars["_check_inv_22"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_22";
    _var_label.innerHTML = "door=open<=>ran(doors)={open}";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_23();
    _var_div.id = "_check_inv_23";
    _machine_vars["_check_inv_23"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_23";
    _var_label.innerHTML = "gear=extended<=>ran(gears)={extended}";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_24();
    _var_div.id = "_check_inv_24";
    _machine_vars["_check_inv_24"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_24";
    _var_label.innerHTML = "gear=retracted<=>ran(gears)={retracted}";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["LandingGear_R6"]()._check_inv_25();
    _var_div.id = "_check_inv_25";
    _machine_vars["_check_inv_25"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_25";
    _var_label.innerHTML = "gear=gear_moving=>door=open";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);

    function updateVisuals () {
      _svg_vars["extension_circuit_gears_4"].setAttribute("stroke-width", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["extension_circuit_doors_4"].setAttribute("stroke", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["ev_close_doors_1"].setAttribute("fill", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["close_switch_1"].setAttribute("fill", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["analogical_switch_1"].setAttribute("fill", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["retraction_circuit_doors_1"].setAttribute("stroke-width", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["lt_door_cylinder_r"].setAttribute("fill", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("#cccccc")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("#88d2f7")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("#cccccc"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.lt))).getValue());
      _svg_vars["lt_gear_cylinder_l"].setAttribute("fill", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("#cccccc")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("#88d2f7")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("#88d2f7"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.lt))).getValue());
      _svg_vars["analogical_switch_1"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["extension_circuit_gears_4"].setAttribute("stroke", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["hydraulic_circuit_5"].setAttribute("stroke", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["retraction_circuit_gears_2"].setAttribute("stroke", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["close_switch_2"].setAttribute("fill", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["eo_close_doors_1"].setAttribute("stroke", (_machine._get_close_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["hydraulic_circuit_4"].setAttribute("stroke-width", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["retraction_circuit_gears_1"].setAttribute("stroke", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["retraction_circuit_gears_4"].setAttribute("stroke", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["rt_door_cylinder_l"].setAttribute("fill", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("#cccccc")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("#88d2f7")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("#88d2f7"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.rt))).getValue());
      _svg_vars["retraction_circuit_gears_3"].setAttribute("stroke", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["analogical_switch_closed"].setAttribute("visibility", (_machine._get_analogical_switch().equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed)).booleanValue() ? new BString("visible") : new BString("hidden")).getValue());
      _svg_vars["eo_extend_gears_2"].setAttribute("stroke", (_machine._get_extend_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["analogical_switch_open"].setAttribute("visibility", (_machine._get_analogical_switch().equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue() ? new BString("visible") : new BString("hidden")).getValue());
      _svg_vars["extension_circuit_gears_1"].setAttribute("stroke", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["hydraulic_circuit_6"].setAttribute("stroke", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["ev_handle"].setAttribute("xlink:href", (_machine._get_handle().equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() ? new BString("img/handle_up.png") : new BString("img/handle_down.png")).getValue());
      _svg_vars["fr_gear_cylinder_r"].setAttribute("fill", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("#cccccc")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("#88d2f7")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("#cccccc"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.fr))).getValue());
      _svg_vars["close_switch_3"].setAttribute("fill", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["eo_close_doors_2"].setAttribute("stroke", (_machine._get_close_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["extension_circuit_doors_3"].setAttribute("stroke", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["ev_extended_gears_1"].setAttribute("fill", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["extension_circuit_doors_4"].setAttribute("stroke-width", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["retraction_circuit_doors_3"].setAttribute("stroke", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["retraction_circuit_doors_2"].setAttribute("stroke-width", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["retraction_circuit_doors_1"].setAttribute("stroke", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["door_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("translate(0,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("translate(90,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("translate(45,0)"))).functionCall(_machine._get_door()).getValue());
      _svg_vars["analogical_switch_3"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["rt_gear_cylinder_r"].setAttribute("fill", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("#cccccc")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("#88d2f7")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("#cccccc"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.rt))).getValue());
      _svg_vars["retraction_circuit_gears_4"].setAttribute("stroke-width", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["analogical_switch_3"].setAttribute("fill", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["retraction_circuit_doors_2"].setAttribute("stroke", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["rt_door_cylinder_r"].setAttribute("fill", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("#cccccc")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("#88d2f7")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("#cccccc"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.rt))).getValue());
      _svg_vars["hydraulic_circuit_1"].setAttribute("stroke", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["fr_gear_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("translate(0,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("translate(90,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("translate(45,0)"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.fr))).getValue());
      _svg_vars["extension_circuit_gears_3"].setAttribute("stroke", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["extension_circuit_doors_2"].setAttribute("stroke-width", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["eo_retract_gears_2"].setAttribute("stroke", (_machine._get_retract_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["extension_circuit_doors_1"].setAttribute("stroke", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["fr_gear_cylinder_l"].setAttribute("fill", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("#cccccc")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("#88d2f7")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("#88d2f7"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.fr))).getValue());
      _svg_vars["analogical_switch_2"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["retraction_circuit_doors_4"].setAttribute("stroke", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["ev_retraction_gears_2"].setAttribute("fill", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["eo_extend_gears_1"].setAttribute("stroke", (_machine._get_extend_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["rt_gear_cylinder_l"].setAttribute("fill", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("#cccccc")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("#88d2f7")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("#88d2f7"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.rt))).getValue());
      _svg_vars["rt_gear_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("translate(0,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("translate(90,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("translate(45,0)"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.rt))).getValue());
      _svg_vars["lt_door_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("translate(0,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("translate(90,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("translate(45,0)"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.lt))).getValue());
      _svg_vars["hydraulic_circuit_3"].setAttribute("stroke", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["eo_general_2"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["eo_open_doors_1"].setAttribute("stroke", (_machine._get_open_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["eo_retract_gears_1"].setAttribute("stroke", (_machine._get_retract_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["ev_general_1"].setAttribute("fill", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["hydraulic_circuit_2"].setAttribute("stroke-width", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["extension_circuit_doors_2"].setAttribute("stroke", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["retraction_circuit_doors_3"].setAttribute("stroke-width", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["retraction_circuit_gears_3"].setAttribute("stroke-width", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["close_switch_1"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["eo_open_doors_2"].setAttribute("stroke", (_machine._get_open_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["extension_circuit_gears_1"].setAttribute("stroke-width", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["ev_open_doors_1"].setAttribute("fill", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["eo_general_3"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["hydraulic_circuit_5"].setAttribute("stroke-width", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["ev_retraction_gears_1"].setAttribute("fill", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["ev_extended_gears_2"].setAttribute("fill", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["extension_circuit_gears_3"].setAttribute("stroke-width", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["ev_open_doors_2"].setAttribute("fill", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["hydraulic_circuit_6"].setAttribute("stroke-width", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["lt_gear_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("translate(0,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("translate(90,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("translate(45,0)"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.lt))).getValue());
      _svg_vars["fr_door_cylinder_l"].setAttribute("fill", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("#cccccc")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("#88d2f7")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("#88d2f7"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.fr))).getValue());
      _svg_vars["close_switch_2"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["extension_circuit_gears_2"].setAttribute("stroke", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["ev_close_doors_2"].setAttribute("fill", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["hydraulic_circuit_4"].setAttribute("stroke", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["extension_circuit_doors_1"].setAttribute("stroke-width", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["rt_door_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("translate(0,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("translate(90,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("translate(45,0)"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.rt))).getValue());
      _svg_vars["hydraulic_circuit_3"].setAttribute("stroke-width", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["retraction_circuit_gears_2"].setAttribute("stroke-width", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["retraction_circuit_doors_4"].setAttribute("stroke-width", (_machine._get_valve_close_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["fr_door_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("translate(0,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("translate(90,0)")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("translate(45,0)"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.fr))).getValue());
      _svg_vars["ev_general_2"].setAttribute("fill", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("blue") : new BString("gray")).getValue());
      _svg_vars["eo_general_1"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["retraction_circuit_gears_1"].setAttribute("stroke-width", (_machine._get_valve_retract_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["fr_door_cylinder_r"].setAttribute("fill", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("#cccccc")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("#88d2f7")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("#cccccc"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.fr))).getValue());
      _svg_vars["hydraulic_circuit_2"].setAttribute("stroke", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BString("#88d2f7") : new BString("#cccccc")).getValue());
      _svg_vars["lt_door_cylinder_l"].setAttribute("fill", new BRelation(new BTuple(new DOOR_STATE(enum_DOOR_STATE.closed), new BString("#cccccc")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.open), new BString("#88d2f7")), new BTuple(new DOOR_STATE(enum_DOOR_STATE.door_moving), new BString("#88d2f7"))).functionCall(_machine._get_doors().functionCall(new POSITION(enum_POSITION.lt))).getValue());
      _svg_vars["extension_circuit_gears_2"].setAttribute("stroke-width", (_machine._get_valve_extend_gear().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["analogical_switch_2"].setAttribute("fill", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["lt_gear_cylinder_r"].setAttribute("fill", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("#cccccc")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("#88d2f7")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("#cccccc"))).functionCall(_machine._get_gears().functionCall(new POSITION(enum_POSITION.lt))).getValue());
      _svg_vars["close_switch_3"].setAttribute("stroke", (_machine._get_general_EV().equal(new BBoolean(true)).booleanValue() ? new BString("green") : new BString("red")).getValue());
      _svg_vars["gear_cylinder_forcer"].setAttribute("transform", new BRelation(new BTuple(new GEAR_STATE(enum_GEAR_STATE.extended), new BString("translate(0,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.retracted), new BString("translate(90,0)")), new BTuple(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new BString("translate(45,0)"))).functionCall(_machine._get_gear()).getValue());
      _svg_vars["extension_circuit_doors_3"].setAttribute("stroke-width", (_machine._get_valve_open_door().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _svg_vars["hydraulic_circuit_1"].setAttribute("stroke-width", (_machine._get_general_valve().equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() ? new BInteger(2) : new BInteger(1)).getValue());
      _machine_vars["analogical_switch"].innerHTML = _included_machines["LandingGear_R6"]()._get_analogical_switch();
      _machine_vars["general_EV"].innerHTML = _included_machines["LandingGear_R6"]()._get_general_EV();
      _machine_vars["general_valve"].innerHTML = _included_machines["LandingGear_R6"]()._get_general_valve();
      _machine_vars["handle_move"].innerHTML = _included_machines["LandingGear_R6"]()._get_handle_move();
      _machine_vars["close_EV"].innerHTML = _included_machines["LandingGear_R6"]()._get_close_EV();
      _machine_vars["extend_EV"].innerHTML = _included_machines["LandingGear_R6"]()._get_extend_EV();
      _machine_vars["open_EV"].innerHTML = _included_machines["LandingGear_R6"]()._get_open_EV();
      _machine_vars["retract_EV"].innerHTML = _included_machines["LandingGear_R6"]()._get_retract_EV();
      _machine_vars["shock_absorber"].innerHTML = _included_machines["LandingGear_R6"]()._get_shock_absorber();
      _machine_vars["valve_close_door"].innerHTML = _included_machines["LandingGear_R6"]()._get_valve_close_door();
      _machine_vars["valve_extend_gear"].innerHTML = _included_machines["LandingGear_R6"]()._get_valve_extend_gear();
      _machine_vars["valve_open_door"].innerHTML = _included_machines["LandingGear_R6"]()._get_valve_open_door();
      _machine_vars["valve_retract_gear"].innerHTML = _included_machines["LandingGear_R6"]()._get_valve_retract_gear();
      _machine_vars["doors"].innerHTML = _included_machines["LandingGear_R6"]()._get_doors();
      _machine_vars["gears"].innerHTML = _included_machines["LandingGear_R6"]()._get_gears();
      _machine_vars["handle"].innerHTML = _included_machines["LandingGear_R6"]()._get_handle();
      _machine_vars["door"].innerHTML = _included_machines["LandingGear_R6"]()._get_door();
      _machine_vars["gear"].innerHTML = _included_machines["LandingGear_R6"]()._get_gear();
      for (let i = 1; i <= 25; i++) {
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
    _machine_events["open_valve_extend_gear"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["open_valve_extend_gear"].style.gridColumn="-1";
    _machine_events["open_valve_extend_gear"].innerHTML = "open_valve_extend_gear";
    _machine_events["open_valve_extend_gear"].parameterNames = [];
    _machine_events["open_valve_extend_gear"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["open_valve_extend_gear"] == null ?? true) {
          transition = _machine._tr_open_valve_extend_gear();
          _transition_list[index]["open_valve_extend_gear"] = transition;
      } else {
          transition = _transition_list[index]["open_valve_extend_gear"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event open_valve_extend_gear is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.open_valve_extend_gear(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("open_valve_extend_gear(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "open_valve_extend_gear", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("open_valve_extend_gear");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["open_valve_extend_gear"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["open_valve_extend_gear"].disabled = true;
            }
            createOptionList("open_valve_extend_gear", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["open_valve_extend_gear"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["open_valve_door_close"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["open_valve_door_close"].style.gridColumn="-1";
    _machine_events["open_valve_door_close"].innerHTML = "open_valve_door_close";
    _machine_events["open_valve_door_close"].parameterNames = [];
    _machine_events["open_valve_door_close"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["open_valve_door_close"] == null ?? true) {
          transition = _machine._tr_open_valve_door_close();
          _transition_list[index]["open_valve_door_close"] = transition;
      } else {
          transition = _transition_list[index]["open_valve_door_close"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event open_valve_door_close is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.open_valve_door_close(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("open_valve_door_close(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "open_valve_door_close", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("open_valve_door_close");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["open_valve_door_close"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["open_valve_door_close"].disabled = true;
            }
            createOptionList("open_valve_door_close", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["open_valve_door_close"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_open_door_last"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_open_door_last_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_open_door_last_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_open_door_last"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_open_door_last"].style.gridColumn="-1";
    _machine_events["env_open_door_last"].innerHTML = "env_open_door_last";
    _machine_events["env_open_door_last"].parameterNames = ["gr", ];
    _machine_events["env_open_door_last"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_open_door_last"] == null ?? true) {
          transition = _machine._tr_env_open_door_last();
          _transition_list[index]["env_open_door_last"] = transition;
      } else {
          transition = _transition_list[index]["env_open_door_last"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_open_door_last is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_open_door_last"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_open_door_last"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_open_door_last"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_open_door_last!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_open_door_last!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_open_door_last"]["gr"].getValue(), ];
        var returnValue = _machine.env_open_door_last(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_open_door_last(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_open_door_last"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_open_door_last", params: parametersJSON});
        updateVisuals();
        _machine_events["env_open_door_last"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_open_door_last");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_open_door_last"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_open_door_last"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_open_door_last"].disabled = true;
            }
            createOptionList("env_open_door_last", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_open_door_last"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["close_valve_extend_gear"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["close_valve_extend_gear"].style.gridColumn="-1";
    _machine_events["close_valve_extend_gear"].innerHTML = "close_valve_extend_gear";
    _machine_events["close_valve_extend_gear"].parameterNames = [];
    _machine_events["close_valve_extend_gear"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["close_valve_extend_gear"] == null ?? true) {
          transition = _machine._tr_close_valve_extend_gear();
          _transition_list[index]["close_valve_extend_gear"] = transition;
      } else {
          transition = _transition_list[index]["close_valve_extend_gear"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event close_valve_extend_gear is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.close_valve_extend_gear(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("close_valve_extend_gear(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "close_valve_extend_gear", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("close_valve_extend_gear");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["close_valve_extend_gear"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["close_valve_extend_gear"].disabled = true;
            }
            createOptionList("close_valve_extend_gear", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["close_valve_extend_gear"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_retract_gear_skip"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_retract_gear_skip_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_retract_gear_skip_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_retract_gear_skip"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_retract_gear_skip"].style.gridColumn="-1";
    _machine_events["env_retract_gear_skip"].innerHTML = "env_retract_gear_skip";
    _machine_events["env_retract_gear_skip"].parameterNames = ["gr", ];
    _machine_events["env_retract_gear_skip"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_retract_gear_skip"] == null ?? true) {
          transition = _machine._tr_env_retract_gear_skip();
          _transition_list[index]["env_retract_gear_skip"] = transition;
      } else {
          transition = _transition_list[index]["env_retract_gear_skip"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_retract_gear_skip is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_retract_gear_skip"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_retract_gear_skip"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_retract_gear_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_retract_gear_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_retract_gear_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_retract_gear_skip"]["gr"].getValue(), ];
        var returnValue = _machine.env_retract_gear_skip(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_retract_gear_skip(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_retract_gear_skip"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_retract_gear_skip", params: parametersJSON});
        updateVisuals();
        _machine_events["env_retract_gear_skip"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_retract_gear_skip");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_retract_gear_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_retract_gear_skip"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_retract_gear_skip"].disabled = true;
            }
            createOptionList("env_retract_gear_skip", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_retract_gear_skip"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_close_analogical_switch"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["env_close_analogical_switch"].style.gridColumn="-1";
    _machine_events["env_close_analogical_switch"].innerHTML = "env_close_analogical_switch";
    _machine_events["env_close_analogical_switch"].parameterNames = [];
    _machine_events["env_close_analogical_switch"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_close_analogical_switch"] == null ?? true) {
          transition = _machine._tr_env_close_analogical_switch();
          _transition_list[index]["env_close_analogical_switch"] = transition;
      } else {
          transition = _transition_list[index]["env_close_analogical_switch"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_close_analogical_switch is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.env_close_analogical_switch(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_close_analogical_switch(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_close_analogical_switch", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("env_close_analogical_switch");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_close_analogical_switch"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_close_analogical_switch"].disabled = true;
            }
            createOptionList("env_close_analogical_switch", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_close_analogical_switch"]);

    _svg_events["open_switch"] = document.getElementById("architecture").contentDocument.getElementById("open_switch");
    _svg_events["open_switch"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_close_analogical_switch"] == null ?? true) {
          transition = _machine._tr_env_close_analogical_switch();
          _transition_list[index]["env_close_analogical_switch"] = transition;
      } else {
          transition = _transition_list[index]["env_close_analogical_switch"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_close_analogical_switch is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.env_close_analogical_switch(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_close_analogical_switch(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_close_analogical_switch", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("env_close_analogical_switch");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_close_analogical_switch"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_close_analogical_switch"].disabled = true;
            }
            createOptionList("env_close_analogical_switch", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_open_analogical_switch"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["env_open_analogical_switch"].style.gridColumn="-1";
    _machine_events["env_open_analogical_switch"].innerHTML = "env_open_analogical_switch";
    _machine_events["env_open_analogical_switch"].parameterNames = [];
    _machine_events["env_open_analogical_switch"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_open_analogical_switch"] == null ?? true) {
          transition = _machine._tr_env_open_analogical_switch();
          _transition_list[index]["env_open_analogical_switch"] = transition;
      } else {
          transition = _transition_list[index]["env_open_analogical_switch"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_open_analogical_switch is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.env_open_analogical_switch(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_open_analogical_switch(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_open_analogical_switch", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("env_open_analogical_switch");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_open_analogical_switch"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_open_analogical_switch"].disabled = true;
            }
            createOptionList("env_open_analogical_switch", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_open_analogical_switch"]);

    _svg_events["close_switch_1"] = document.getElementById("architecture").contentDocument.getElementById("close_switch_1");
    _svg_events["close_switch_1"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_open_analogical_switch"] == null ?? true) {
          transition = _machine._tr_env_open_analogical_switch();
          _transition_list[index]["env_open_analogical_switch"] = transition;
      } else {
          transition = _transition_list[index]["env_open_analogical_switch"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_open_analogical_switch is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.env_open_analogical_switch(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_open_analogical_switch(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_open_analogical_switch", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("env_open_analogical_switch");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_open_analogical_switch"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_open_analogical_switch"].disabled = true;
            }
            createOptionList("env_open_analogical_switch", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["toggle_handle_up"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["toggle_handle_up"].style.gridColumn="-1";
    _machine_events["toggle_handle_up"].innerHTML = "toggle_handle_up";
    _machine_events["toggle_handle_up"].parameterNames = [];
    _machine_events["toggle_handle_up"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["toggle_handle_up"] == null ?? true) {
          transition = _machine._tr_toggle_handle_up();
          _transition_list[index]["toggle_handle_up"] = transition;
      } else {
          transition = _transition_list[index]["toggle_handle_up"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event toggle_handle_up is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.toggle_handle_up(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("toggle_handle_up(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "toggle_handle_up", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("toggle_handle_up");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["toggle_handle_up"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["toggle_handle_up"].disabled = true;
            }
            createOptionList("toggle_handle_up", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["toggle_handle_up"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["land_plane"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["land_plane"].style.gridColumn="-1";
    _machine_events["land_plane"].innerHTML = "land_plane";
    _machine_events["land_plane"].parameterNames = [];
    _machine_events["land_plane"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["land_plane"] == null ?? true) {
          transition = _machine._tr_land_plane();
          _transition_list[index]["land_plane"] = transition;
      } else {
          transition = _transition_list[index]["land_plane"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event land_plane is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.land_plane(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("land_plane(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "land_plane", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("land_plane");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["land_plane"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["land_plane"].disabled = true;
            }
            createOptionList("land_plane", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["land_plane"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_extend_gear_skip"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_extend_gear_skip_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_extend_gear_skip_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_extend_gear_skip"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_extend_gear_skip"].style.gridColumn="-1";
    _machine_events["env_extend_gear_skip"].innerHTML = "env_extend_gear_skip";
    _machine_events["env_extend_gear_skip"].parameterNames = ["gr", ];
    _machine_events["env_extend_gear_skip"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_extend_gear_skip"] == null ?? true) {
          transition = _machine._tr_env_extend_gear_skip();
          _transition_list[index]["env_extend_gear_skip"] = transition;
      } else {
          transition = _transition_list[index]["env_extend_gear_skip"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_extend_gear_skip is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_extend_gear_skip"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_extend_gear_skip"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_extend_gear_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_extend_gear_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_extend_gear_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_extend_gear_skip"]["gr"].getValue(), ];
        var returnValue = _machine.env_extend_gear_skip(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_extend_gear_skip(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_extend_gear_skip"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_extend_gear_skip", params: parametersJSON});
        updateVisuals();
        _machine_events["env_extend_gear_skip"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_extend_gear_skip");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_extend_gear_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_extend_gear_skip"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_extend_gear_skip"].disabled = true;
            }
            createOptionList("env_extend_gear_skip", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_extend_gear_skip"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stop_stimulate_open_door_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stop_stimulate_open_door_valve"].style.gridColumn="-1";
    _machine_events["con_stop_stimulate_open_door_valve"].innerHTML = "con_stop_stimulate_open_door_valve";
    _machine_events["con_stop_stimulate_open_door_valve"].parameterNames = [];
    _machine_events["con_stop_stimulate_open_door_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stop_stimulate_open_door_valve"] == null ?? true) {
          transition = _machine._tr_con_stop_stimulate_open_door_valve();
          _transition_list[index]["con_stop_stimulate_open_door_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stop_stimulate_open_door_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stop_stimulate_open_door_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stop_stimulate_open_door_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stop_stimulate_open_door_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stop_stimulate_open_door_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stop_stimulate_open_door_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stop_stimulate_open_door_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stop_stimulate_open_door_valve"].disabled = true;
            }
            createOptionList("con_stop_stimulate_open_door_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stop_stimulate_open_door_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["open_valve_retract_gear"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["open_valve_retract_gear"].style.gridColumn="-1";
    _machine_events["open_valve_retract_gear"].innerHTML = "open_valve_retract_gear";
    _machine_events["open_valve_retract_gear"].parameterNames = [];
    _machine_events["open_valve_retract_gear"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["open_valve_retract_gear"] == null ?? true) {
          transition = _machine._tr_open_valve_retract_gear();
          _transition_list[index]["open_valve_retract_gear"] = transition;
      } else {
          transition = _transition_list[index]["open_valve_retract_gear"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event open_valve_retract_gear is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.open_valve_retract_gear(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("open_valve_retract_gear(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "open_valve_retract_gear", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("open_valve_retract_gear");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["open_valve_retract_gear"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["open_valve_retract_gear"].disabled = true;
            }
            createOptionList("open_valve_retract_gear", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["open_valve_retract_gear"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["evn_open_general_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["evn_open_general_valve"].style.gridColumn="-1";
    _machine_events["evn_open_general_valve"].innerHTML = "evn_open_general_valve";
    _machine_events["evn_open_general_valve"].parameterNames = [];
    _machine_events["evn_open_general_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["evn_open_general_valve"] == null ?? true) {
          transition = _machine._tr_evn_open_general_valve();
          _transition_list[index]["evn_open_general_valve"] = transition;
      } else {
          transition = _transition_list[index]["evn_open_general_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event evn_open_general_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.evn_open_general_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("evn_open_general_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "evn_open_general_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("evn_open_general_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["evn_open_general_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["evn_open_general_valve"].disabled = true;
            }
            createOptionList("evn_open_general_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["evn_open_general_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stimulate_retract_gear_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stimulate_retract_gear_valve"].style.gridColumn="-1";
    _machine_events["con_stimulate_retract_gear_valve"].innerHTML = "con_stimulate_retract_gear_valve";
    _machine_events["con_stimulate_retract_gear_valve"].parameterNames = [];
    _machine_events["con_stimulate_retract_gear_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stimulate_retract_gear_valve"] == null ?? true) {
          transition = _machine._tr_con_stimulate_retract_gear_valve();
          _transition_list[index]["con_stimulate_retract_gear_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stimulate_retract_gear_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stimulate_retract_gear_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stimulate_retract_gear_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stimulate_retract_gear_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stimulate_retract_gear_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stimulate_retract_gear_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stimulate_retract_gear_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stimulate_retract_gear_valve"].disabled = true;
            }
            createOptionList("con_stimulate_retract_gear_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stimulate_retract_gear_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_open_door_skip"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_open_door_skip_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_open_door_skip_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_open_door_skip"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_open_door_skip"].style.gridColumn="-1";
    _machine_events["env_open_door_skip"].innerHTML = "env_open_door_skip";
    _machine_events["env_open_door_skip"].parameterNames = ["gr", ];
    _machine_events["env_open_door_skip"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_open_door_skip"] == null ?? true) {
          transition = _machine._tr_env_open_door_skip();
          _transition_list[index]["env_open_door_skip"] = transition;
      } else {
          transition = _transition_list[index]["env_open_door_skip"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_open_door_skip is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_open_door_skip"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_open_door_skip"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_open_door_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_open_door_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_open_door_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_open_door_skip"]["gr"].getValue(), ];
        var returnValue = _machine.env_open_door_skip(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_open_door_skip(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_open_door_skip"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_open_door_skip", params: parametersJSON});
        updateVisuals();
        _machine_events["env_open_door_skip"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_open_door_skip");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_open_door_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_open_door_skip"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_open_door_skip"].disabled = true;
            }
            createOptionList("env_open_door_skip", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_open_door_skip"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stop_stimulate_retract_gear_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stop_stimulate_retract_gear_valve"].style.gridColumn="-1";
    _machine_events["con_stop_stimulate_retract_gear_valve"].innerHTML = "con_stop_stimulate_retract_gear_valve";
    _machine_events["con_stop_stimulate_retract_gear_valve"].parameterNames = [];
    _machine_events["con_stop_stimulate_retract_gear_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stop_stimulate_retract_gear_valve"] == null ?? true) {
          transition = _machine._tr_con_stop_stimulate_retract_gear_valve();
          _transition_list[index]["con_stop_stimulate_retract_gear_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stop_stimulate_retract_gear_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stop_stimulate_retract_gear_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stop_stimulate_retract_gear_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stop_stimulate_retract_gear_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stop_stimulate_retract_gear_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stop_stimulate_retract_gear_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stop_stimulate_retract_gear_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stop_stimulate_retract_gear_valve"].disabled = true;
            }
            createOptionList("con_stop_stimulate_retract_gear_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stop_stimulate_retract_gear_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stimulate_close_door_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stimulate_close_door_valve"].style.gridColumn="-1";
    _machine_events["con_stimulate_close_door_valve"].innerHTML = "con_stimulate_close_door_valve";
    _machine_events["con_stimulate_close_door_valve"].parameterNames = [];
    _machine_events["con_stimulate_close_door_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stimulate_close_door_valve"] == null ?? true) {
          transition = _machine._tr_con_stimulate_close_door_valve();
          _transition_list[index]["con_stimulate_close_door_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stimulate_close_door_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stimulate_close_door_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stimulate_close_door_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stimulate_close_door_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stimulate_close_door_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stimulate_close_door_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stimulate_close_door_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stimulate_close_door_valve"].disabled = true;
            }
            createOptionList("con_stimulate_close_door_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stimulate_close_door_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stimulate_extend_gear_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stimulate_extend_gear_valve"].style.gridColumn="-1";
    _machine_events["con_stimulate_extend_gear_valve"].innerHTML = "con_stimulate_extend_gear_valve";
    _machine_events["con_stimulate_extend_gear_valve"].parameterNames = [];
    _machine_events["con_stimulate_extend_gear_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stimulate_extend_gear_valve"] == null ?? true) {
          transition = _machine._tr_con_stimulate_extend_gear_valve();
          _transition_list[index]["con_stimulate_extend_gear_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stimulate_extend_gear_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stimulate_extend_gear_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stimulate_extend_gear_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stimulate_extend_gear_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stimulate_extend_gear_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stimulate_extend_gear_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stimulate_extend_gear_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stimulate_extend_gear_valve"].disabled = true;
            }
            createOptionList("con_stimulate_extend_gear_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stimulate_extend_gear_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_start_retracting_first"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_start_retracting_first_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_start_retracting_first_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_start_retracting_first"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_start_retracting_first"].style.gridColumn="-1";
    _machine_events["env_start_retracting_first"].innerHTML = "env_start_retracting_first";
    _machine_events["env_start_retracting_first"].parameterNames = ["gr", ];
    _machine_events["env_start_retracting_first"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_start_retracting_first"] == null ?? true) {
          transition = _machine._tr_env_start_retracting_first();
          _transition_list[index]["env_start_retracting_first"] = transition;
      } else {
          transition = _transition_list[index]["env_start_retracting_first"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_start_retracting_first is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_start_retracting_first"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_start_retracting_first"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_start_retracting_first"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_start_retracting_first!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_start_retracting_first!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_start_retracting_first"]["gr"].getValue(), ];
        var returnValue = _machine.env_start_retracting_first(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_start_retracting_first(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_start_retracting_first"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_start_retracting_first", params: parametersJSON});
        updateVisuals();
        _machine_events["env_start_retracting_first"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_start_retracting_first");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_start_retracting_first"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_start_retracting_first"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_start_retracting_first"].disabled = true;
            }
            createOptionList("env_start_retracting_first", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_start_retracting_first"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_start_open_door"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_start_open_door_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_start_open_door_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_start_open_door"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_start_open_door"].style.gridColumn="-1";
    _machine_events["env_start_open_door"].innerHTML = "env_start_open_door";
    _machine_events["env_start_open_door"].parameterNames = ["gr", ];
    _machine_events["env_start_open_door"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_start_open_door"] == null ?? true) {
          transition = _machine._tr_env_start_open_door();
          _transition_list[index]["env_start_open_door"] = transition;
      } else {
          transition = _transition_list[index]["env_start_open_door"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_start_open_door is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_start_open_door"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_start_open_door"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_start_open_door"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_start_open_door!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_start_open_door!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_start_open_door"]["gr"].getValue(), ];
        var returnValue = _machine.env_start_open_door(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_start_open_door(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_start_open_door"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_start_open_door", params: parametersJSON});
        updateVisuals();
        _machine_events["env_start_open_door"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_start_open_door");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_start_open_door"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_start_open_door"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_start_open_door"].disabled = true;
            }
            createOptionList("env_start_open_door", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_start_open_door"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["evn_close_general_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["evn_close_general_valve"].style.gridColumn="-1";
    _machine_events["evn_close_general_valve"].innerHTML = "evn_close_general_valve";
    _machine_events["evn_close_general_valve"].parameterNames = [];
    _machine_events["evn_close_general_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["evn_close_general_valve"] == null ?? true) {
          transition = _machine._tr_evn_close_general_valve();
          _transition_list[index]["evn_close_general_valve"] = transition;
      } else {
          transition = _transition_list[index]["evn_close_general_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event evn_close_general_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.evn_close_general_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("evn_close_general_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "evn_close_general_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("evn_close_general_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["evn_close_general_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["evn_close_general_valve"].disabled = true;
            }
            createOptionList("evn_close_general_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["evn_close_general_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_retract_gear_last"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_retract_gear_last_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_retract_gear_last_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_retract_gear_last"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_retract_gear_last"].style.gridColumn="-1";
    _machine_events["env_retract_gear_last"].innerHTML = "env_retract_gear_last";
    _machine_events["env_retract_gear_last"].parameterNames = ["gr", ];
    _machine_events["env_retract_gear_last"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_retract_gear_last"] == null ?? true) {
          transition = _machine._tr_env_retract_gear_last();
          _transition_list[index]["env_retract_gear_last"] = transition;
      } else {
          transition = _transition_list[index]["env_retract_gear_last"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_retract_gear_last is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_retract_gear_last"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_retract_gear_last"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_retract_gear_last"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_retract_gear_last!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_retract_gear_last!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_retract_gear_last"]["gr"].getValue(), ];
        var returnValue = _machine.env_retract_gear_last(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_retract_gear_last(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_retract_gear_last"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_retract_gear_last", params: parametersJSON});
        updateVisuals();
        _machine_events["env_retract_gear_last"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_retract_gear_last");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_retract_gear_last"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_retract_gear_last"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_retract_gear_last"].disabled = true;
            }
            createOptionList("env_retract_gear_last", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_retract_gear_last"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["close_valve_door_close"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["close_valve_door_close"].style.gridColumn="-1";
    _machine_events["close_valve_door_close"].innerHTML = "close_valve_door_close";
    _machine_events["close_valve_door_close"].parameterNames = [];
    _machine_events["close_valve_door_close"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["close_valve_door_close"] == null ?? true) {
          transition = _machine._tr_close_valve_door_close();
          _transition_list[index]["close_valve_door_close"] = transition;
      } else {
          transition = _transition_list[index]["close_valve_door_close"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event close_valve_door_close is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.close_valve_door_close(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("close_valve_door_close(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "close_valve_door_close", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("close_valve_door_close");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["close_valve_door_close"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["close_valve_door_close"].disabled = true;
            }
            createOptionList("close_valve_door_close", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["close_valve_door_close"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stop_stimulate_extend_gear_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stop_stimulate_extend_gear_valve"].style.gridColumn="-1";
    _machine_events["con_stop_stimulate_extend_gear_valve"].innerHTML = "con_stop_stimulate_extend_gear_valve";
    _machine_events["con_stop_stimulate_extend_gear_valve"].parameterNames = [];
    _machine_events["con_stop_stimulate_extend_gear_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stop_stimulate_extend_gear_valve"] == null ?? true) {
          transition = _machine._tr_con_stop_stimulate_extend_gear_valve();
          _transition_list[index]["con_stop_stimulate_extend_gear_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stop_stimulate_extend_gear_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stop_stimulate_extend_gear_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stop_stimulate_extend_gear_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stop_stimulate_extend_gear_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stop_stimulate_extend_gear_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stop_stimulate_extend_gear_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stop_stimulate_extend_gear_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stop_stimulate_extend_gear_valve"].disabled = true;
            }
            createOptionList("con_stop_stimulate_extend_gear_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stop_stimulate_extend_gear_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_close_door"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_close_door_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_close_door_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_close_door"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_close_door"].style.gridColumn="-1";
    _machine_events["env_close_door"].innerHTML = "env_close_door";
    _machine_events["env_close_door"].parameterNames = ["gr", ];
    _machine_events["env_close_door"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_close_door"] == null ?? true) {
          transition = _machine._tr_env_close_door();
          _transition_list[index]["env_close_door"] = transition;
      } else {
          transition = _transition_list[index]["env_close_door"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_close_door is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_close_door"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_close_door"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_close_door"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_close_door!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_close_door!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_close_door"]["gr"].getValue(), ];
        var returnValue = _machine.env_close_door(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_close_door(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_close_door"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_close_door", params: parametersJSON});
        updateVisuals();
        _machine_events["env_close_door"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_close_door");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_close_door"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_close_door"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_close_door"].disabled = true;
            }
            createOptionList("env_close_door", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_close_door"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stimulate_general_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stimulate_general_valve"].style.gridColumn="-1";
    _machine_events["con_stimulate_general_valve"].innerHTML = "con_stimulate_general_valve";
    _machine_events["con_stimulate_general_valve"].parameterNames = [];
    _machine_events["con_stimulate_general_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stimulate_general_valve"] == null ?? true) {
          transition = _machine._tr_con_stimulate_general_valve();
          _transition_list[index]["con_stimulate_general_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stimulate_general_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stimulate_general_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stimulate_general_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stimulate_general_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stimulate_general_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stimulate_general_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stimulate_general_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stimulate_general_valve"].disabled = true;
            }
            createOptionList("con_stimulate_general_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stimulate_general_valve"]);

    _svg_events["con_stimulate_general_valve"] = document.getElementById("architecture").contentDocument.getElementById("con_stimulate_general_valve");
    _svg_events["con_stimulate_general_valve"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stimulate_general_valve"] == null ?? true) {
          transition = _machine._tr_con_stimulate_general_valve();
          _transition_list[index]["con_stimulate_general_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stimulate_general_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stimulate_general_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stimulate_general_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stimulate_general_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stimulate_general_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stimulate_general_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stimulate_general_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stimulate_general_valve"].disabled = true;
            }
            createOptionList("con_stimulate_general_valve", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_close_door_skip"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_close_door_skip_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_close_door_skip_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_close_door_skip"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_close_door_skip"].style.gridColumn="-1";
    _machine_events["env_close_door_skip"].innerHTML = "env_close_door_skip";
    _machine_events["env_close_door_skip"].parameterNames = ["gr", ];
    _machine_events["env_close_door_skip"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_close_door_skip"] == null ?? true) {
          transition = _machine._tr_env_close_door_skip();
          _transition_list[index]["env_close_door_skip"] = transition;
      } else {
          transition = _transition_list[index]["env_close_door_skip"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_close_door_skip is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_close_door_skip"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_close_door_skip"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_close_door_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_close_door_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_close_door_skip!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_close_door_skip"]["gr"].getValue(), ];
        var returnValue = _machine.env_close_door_skip(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_close_door_skip(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_close_door_skip"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_close_door_skip", params: parametersJSON});
        updateVisuals();
        _machine_events["env_close_door_skip"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_close_door_skip");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_close_door_skip"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_close_door_skip"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_close_door_skip"].disabled = true;
            }
            createOptionList("env_close_door_skip", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_close_door_skip"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["close_valve_retract_gear"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["close_valve_retract_gear"].style.gridColumn="-1";
    _machine_events["close_valve_retract_gear"].innerHTML = "close_valve_retract_gear";
    _machine_events["close_valve_retract_gear"].parameterNames = [];
    _machine_events["close_valve_retract_gear"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["close_valve_retract_gear"] == null ?? true) {
          transition = _machine._tr_close_valve_retract_gear();
          _transition_list[index]["close_valve_retract_gear"] = transition;
      } else {
          transition = _transition_list[index]["close_valve_retract_gear"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event close_valve_retract_gear is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.close_valve_retract_gear(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("close_valve_retract_gear(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "close_valve_retract_gear", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("close_valve_retract_gear");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["close_valve_retract_gear"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["close_valve_retract_gear"].disabled = true;
            }
            createOptionList("close_valve_retract_gear", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["close_valve_retract_gear"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["open_valve_door_open"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["open_valve_door_open"].style.gridColumn="-1";
    _machine_events["open_valve_door_open"].innerHTML = "open_valve_door_open";
    _machine_events["open_valve_door_open"].parameterNames = [];
    _machine_events["open_valve_door_open"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["open_valve_door_open"] == null ?? true) {
          transition = _machine._tr_open_valve_door_open();
          _transition_list[index]["open_valve_door_open"] = transition;
      } else {
          transition = _transition_list[index]["open_valve_door_open"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event open_valve_door_open is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.open_valve_door_open(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("open_valve_door_open(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "open_valve_door_open", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("open_valve_door_open");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["open_valve_door_open"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["open_valve_door_open"].disabled = true;
            }
            createOptionList("open_valve_door_open", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["open_valve_door_open"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stop_stimulate_general_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stop_stimulate_general_valve"].style.gridColumn="-1";
    _machine_events["con_stop_stimulate_general_valve"].innerHTML = "con_stop_stimulate_general_valve";
    _machine_events["con_stop_stimulate_general_valve"].parameterNames = [];
    _machine_events["con_stop_stimulate_general_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stop_stimulate_general_valve"] == null ?? true) {
          transition = _machine._tr_con_stop_stimulate_general_valve();
          _transition_list[index]["con_stop_stimulate_general_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stop_stimulate_general_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stop_stimulate_general_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stop_stimulate_general_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stop_stimulate_general_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stop_stimulate_general_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stop_stimulate_general_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stop_stimulate_general_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stop_stimulate_general_valve"].disabled = true;
            }
            createOptionList("con_stop_stimulate_general_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stop_stimulate_general_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_start_close_door"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_start_close_door_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_start_close_door_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_start_close_door"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_start_close_door"].style.gridColumn="-1";
    _machine_events["env_start_close_door"].innerHTML = "env_start_close_door";
    _machine_events["env_start_close_door"].parameterNames = ["gr", ];
    _machine_events["env_start_close_door"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_start_close_door"] == null ?? true) {
          transition = _machine._tr_env_start_close_door();
          _transition_list[index]["env_start_close_door"] = transition;
      } else {
          transition = _transition_list[index]["env_start_close_door"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_start_close_door is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_start_close_door"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_start_close_door"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_start_close_door"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_start_close_door!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_start_close_door!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_start_close_door"]["gr"].getValue(), ];
        var returnValue = _machine.env_start_close_door(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_start_close_door(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_start_close_door"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_start_close_door", params: parametersJSON});
        updateVisuals();
        _machine_events["env_start_close_door"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_start_close_door");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_start_close_door"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_start_close_door"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_start_close_door"].disabled = true;
            }
            createOptionList("env_start_close_door", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_start_close_door"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stimulate_open_door_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stimulate_open_door_valve"].style.gridColumn="-1";
    _machine_events["con_stimulate_open_door_valve"].innerHTML = "con_stimulate_open_door_valve";
    _machine_events["con_stimulate_open_door_valve"].parameterNames = [];
    _machine_events["con_stimulate_open_door_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stimulate_open_door_valve"] == null ?? true) {
          transition = _machine._tr_con_stimulate_open_door_valve();
          _transition_list[index]["con_stimulate_open_door_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stimulate_open_door_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stimulate_open_door_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stimulate_open_door_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stimulate_open_door_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stimulate_open_door_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stimulate_open_door_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stimulate_open_door_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stimulate_open_door_valve"].disabled = true;
            }
            createOptionList("con_stimulate_open_door_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stimulate_open_door_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_extend_gear_last"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_extend_gear_last_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_extend_gear_last_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_extend_gear_last"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_extend_gear_last"].style.gridColumn="-1";
    _machine_events["env_extend_gear_last"].innerHTML = "env_extend_gear_last";
    _machine_events["env_extend_gear_last"].parameterNames = ["gr", ];
    _machine_events["env_extend_gear_last"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_extend_gear_last"] == null ?? true) {
          transition = _machine._tr_env_extend_gear_last();
          _transition_list[index]["env_extend_gear_last"] = transition;
      } else {
          transition = _transition_list[index]["env_extend_gear_last"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_extend_gear_last is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_extend_gear_last"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_extend_gear_last"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_extend_gear_last"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_extend_gear_last!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_extend_gear_last!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_extend_gear_last"]["gr"].getValue(), ];
        var returnValue = _machine.env_extend_gear_last(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_extend_gear_last(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_extend_gear_last"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_extend_gear_last", params: parametersJSON});
        updateVisuals();
        _machine_events["env_extend_gear_last"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_extend_gear_last");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_extend_gear_last"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_extend_gear_last"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_extend_gear_last"].disabled = true;
            }
            createOptionList("env_extend_gear_last", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_extend_gear_last"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["con_stop_stimulate_close_door_valve"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["con_stop_stimulate_close_door_valve"].style.gridColumn="-1";
    _machine_events["con_stop_stimulate_close_door_valve"].innerHTML = "con_stop_stimulate_close_door_valve";
    _machine_events["con_stop_stimulate_close_door_valve"].parameterNames = [];
    _machine_events["con_stop_stimulate_close_door_valve"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["con_stop_stimulate_close_door_valve"] == null ?? true) {
          transition = _machine._tr_con_stop_stimulate_close_door_valve();
          _transition_list[index]["con_stop_stimulate_close_door_valve"] = transition;
      } else {
          transition = _transition_list[index]["con_stop_stimulate_close_door_valve"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event con_stop_stimulate_close_door_valve is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.con_stop_stimulate_close_door_valve(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("con_stop_stimulate_close_door_valve(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "con_stop_stimulate_close_door_valve", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("con_stop_stimulate_close_door_valve");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["con_stop_stimulate_close_door_valve"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["con_stop_stimulate_close_door_valve"].disabled = true;
            }
            createOptionList("con_stop_stimulate_close_door_valve", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["con_stop_stimulate_close_door_valve"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["begin_flying"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["begin_flying"].style.gridColumn="-1";
    _machine_events["begin_flying"].innerHTML = "begin_flying";
    _machine_events["begin_flying"].parameterNames = [];
    _machine_events["begin_flying"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["begin_flying"] == null ?? true) {
          transition = _machine._tr_begin_flying();
          _transition_list[index]["begin_flying"] = transition;
      } else {
          transition = _transition_list[index]["begin_flying"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event begin_flying is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.begin_flying(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("begin_flying(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "begin_flying", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("begin_flying");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["begin_flying"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["begin_flying"].disabled = true;
            }
            createOptionList("begin_flying", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["begin_flying"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["close_valve_door_open"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["close_valve_door_open"].style.gridColumn="-1";
    _machine_events["close_valve_door_open"].innerHTML = "close_valve_door_open";
    _machine_events["close_valve_door_open"].parameterNames = [];
    _machine_events["close_valve_door_open"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["close_valve_door_open"] == null ?? true) {
          transition = _machine._tr_close_valve_door_open();
          _transition_list[index]["close_valve_door_open"] = transition;
      } else {
          transition = _transition_list[index]["close_valve_door_open"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event close_valve_door_open is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.close_valve_door_open(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("close_valve_door_open(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "close_valve_door_open", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("close_valve_door_open");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["close_valve_door_open"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["close_valve_door_open"].disabled = true;
            }
            createOptionList("close_valve_door_open", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["close_valve_door_open"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["toggle_handle_down"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["toggle_handle_down"].style.gridColumn="-1";
    _machine_events["toggle_handle_down"].innerHTML = "toggle_handle_down";
    _machine_events["toggle_handle_down"].parameterNames = [];
    _machine_events["toggle_handle_down"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["toggle_handle_down"] == null ?? true) {
          transition = _machine._tr_toggle_handle_down();
          _transition_list[index]["toggle_handle_down"] = transition;
      } else {
          transition = _transition_list[index]["toggle_handle_down"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event toggle_handle_down is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.toggle_handle_down(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("toggle_handle_down(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "toggle_handle_down", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("toggle_handle_down");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["toggle_handle_down"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["toggle_handle_down"].disabled = true;
            }
            createOptionList("toggle_handle_down", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["toggle_handle_down"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["env_start_extending"] = document.createElement("button");
    var gr_label = document.createElement("label")
    gr_label.textContent = "gr:";
    gr_label.htmlFor="gr";
    _param_div.appendChild(gr_label);
    var gr = document.createElement("input");
    gr.id="gr";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="env_start_extending_gr_datalist";
    _param_div.appendChild(_param_datalist);
    gr.setAttribute("list", "env_start_extending_gr_datalist");
    gr.getValue = function() {return this.value == "" ? null : POSITION["get_" + this.value]()}
    gr.setValue = function(value) {this.value = value}
    gr.parseValue = function(value) {return value == "" ? null : POSITION["get_" + value]()}
    _param_div.appendChild(gr);
    _machine_events["env_start_extending"]["gr"] = gr;

    _operations_view.appendChild(_param_div);


    _machine_events["env_start_extending"].style.gridColumn="-1";
    _machine_events["env_start_extending"].innerHTML = "env_start_extending";
    _machine_events["env_start_extending"].parameterNames = ["gr", ];
    _machine_events["env_start_extending"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["env_start_extending"] == null ?? true) {
          transition = _machine._tr_env_start_extending();
          _transition_list[index]["env_start_extending"] = transition;
      } else {
          transition = _transition_list[index]["env_start_extending"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event env_start_extending is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["env_start_extending"]["gr"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["gr"].map(function(e, i) {
                        _machine_events["env_start_extending"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.gr ?? _machine_events["env_start_extending"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event env_start_extending!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event env_start_extending!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.gr ?? _machine_events["env_start_extending"]["gr"].getValue(), ];
        var returnValue = _machine.env_start_extending(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("env_start_extending(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["gr"] = _machine_events["env_start_extending"]["gr"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "env_start_extending", params: parametersJSON});
        updateVisuals();
        _machine_events["env_start_extending"]["gr"].setValue("")
        triggerSimulationOnInteraction("env_start_extending");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.gr ?? _machine_events["env_start_extending"]["gr"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["env_start_extending"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["env_start_extending"].disabled = true;
            }
            createOptionList("env_start_extending", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["env_start_extending"]);



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
          modelName: "LandingGear_R6"
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
        _machine = new LandingGear_R6();
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
          modelName: "LandingGear_R6"
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