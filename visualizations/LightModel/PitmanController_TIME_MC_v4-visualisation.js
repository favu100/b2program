import PitmanController_TIME_MC_v4 from "https://favu100.github.io/b2program/visualizations/LightModel/PitmanController_TIME_MC_v4.js";
import {SelectError} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BUtils.js";
import {enum_PITMAN_POSITION} from "https://favu100.github.io/b2program/visualizations/LightModel/Sensors.js"
import {PITMAN_POSITION} from "https://favu100.github.io/b2program/visualizations/LightModel/Sensors.js"
import {enum_SWITCH_STATUS} from "https://favu100.github.io/b2program/visualizations/LightModel/Sensors.js"
import {SWITCH_STATUS} from "https://favu100.github.io/b2program/visualizations/LightModel/Sensors.js"
import {enum_KEY_STATE} from "https://favu100.github.io/b2program/visualizations/LightModel/Sensors.js"
import {KEY_STATE} from "https://favu100.github.io/b2program/visualizations/LightModel/Sensors.js"
import {enum_TIMERS} from "https://favu100.github.io/b2program/visualizations/LightModel/GenericTimersMC.js"
import {TIMERS} from "https://favu100.github.io/b2program/visualizations/LightModel/GenericTimersMC.js"
import {enum_DIRECTIONS} from "https://favu100.github.io/b2program/visualizations/LightModel/BlinkLamps_v3.js"
import {DIRECTIONS} from "https://favu100.github.io/b2program/visualizations/LightModel/BlinkLamps_v3.js"
import {BTuple} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BTuple.js";
import {BSet} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BSet.js";
import {BRelation} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BRelation.js";
import {BInteger} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BInteger.js";
import {BBoolean} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BBoolean.js";
import {BObject} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BObject.js";
import {BString} from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BString.js";

import {Activation} from "https://favu100.github.io/b2program/visualizations/LightModel/simulation/Activation.js";
import {ActivationKind} from "https://favu100.github.io/b2program/visualizations/LightModel/simulation/ActivationKind.js";

window.onload = function() {
    initialize();
}

function initialize() {
    var _machine = new PitmanController_TIME_MC_v4();
    var _state_list = [];
    var _transition_list = [];
    var _description_list = [];
    var _included_machines = {};
    _included_machines["PitmanController_TIME_MC_v4"] = function(){return _machine};
    _included_machines["BlinkLamps_v3"] = function(){return _machine._BlinkLamps_v3};
    _included_machines["Sensors"] = function(){return _machine._Sensors};
    _included_machines["GenericTimersMC"] = function(){return _machine._GenericTimersMC};
    var _state_view_vars = document.getElementById("_state_view_variables");
    var _state_view_consts = document.getElementById("_state_view_constants");
    var _state_view_sets = document.getElementById("_state_view_sets");
    var _state_view_invariant = document.getElementById("_state_view_invariant");
    var _svg_vars = {}
        _svg_vars["circle-PitmanDownward"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("circle-PitmanDownward")
        _svg_vars["PitmanNeutral"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("PitmanNeutral")
        _svg_vars["A-left"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("A-left")
        _svg_vars["key-inserted"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("key-inserted")
        _svg_vars["A-right"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("A-right")
        _svg_vars["car_outline"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("car_outline")
        _svg_vars["B-right"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("B-right")
        _svg_vars["back-window"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("back-window")
        _svg_vars["C-left"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("C-left")
        _svg_vars["C-right"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("C-right")
        _svg_vars["timer-text"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("timer-text")
        _svg_vars["engine-start"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("engine-start")
        _svg_vars["key-on-position"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("key-on-position")
        _svg_vars["warningLight"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("warningLight")
        _svg_vars["circle-PitmanUpward"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("circle-PitmanUpward")
        _svg_vars["key-on-text"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("key-on-text")
        _svg_vars["PitmanDownward"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("PitmanDownward")
        _svg_vars["B-left"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("B-left")
        _svg_vars["PitmanUpward"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("PitmanUpward")
        _svg_vars["front-window"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("front-window")
    var _machine_vars = {}
    var _var_label;
    var _var_div;
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_active_blinkers();
    _var_div.id = "_var_active_blinkers";
    _machine_vars["active_blinkers"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_active_blinkers";
    _var_label.innerHTML = "BlinkLamps_v3.active_blinkers";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_remaining_blinks();
    _var_div.id = "_var_remaining_blinks";
    _machine_vars["remaining_blinks"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_remaining_blinks";
    _var_label.innerHTML = "BlinkLamps_v3.remaining_blinks";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_onCycle();
    _var_div.id = "_var_onCycle";
    _machine_vars["onCycle"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_onCycle";
    _var_label.innerHTML = "BlinkLamps_v3.onCycle";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_blinkLeft();
    _var_div.id = "_var_blinkLeft";
    _machine_vars["blinkLeft"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_blinkLeft";
    _var_label.innerHTML = "BlinkLamps_v3.blinkLeft";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_blinkRight();
    _var_div.id = "_var_blinkRight";
    _machine_vars["blinkRight"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_blinkRight";
    _var_label.innerHTML = "BlinkLamps_v3.blinkRight";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get_hazardWarningSwitchOn();
    _var_div.id = "_var_hazardWarningSwitchOn";
    _machine_vars["hazardWarningSwitchOn"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_hazardWarningSwitchOn";
    _var_label.innerHTML = "Sensors.hazardWarningSwitchOn";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get_pitmanArmUpDown();
    _var_div.id = "_var_pitmanArmUpDown";
    _machine_vars["pitmanArmUpDown"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_pitmanArmUpDown";
    _var_label.innerHTML = "Sensors.pitmanArmUpDown";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get_keyState();
    _var_div.id = "_var_keyState";
    _machine_vars["keyState"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_keyState";
    _var_label.innerHTML = "Sensors.keyState";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get_engineOn();
    _var_div.id = "_var_engineOn";
    _machine_vars["engineOn"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_engineOn";
    _var_label.innerHTML = "Sensors.engineOn";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["GenericTimersMC"]()._get_curDeadlines();
    _var_div.id = "_var_curDeadlines";
    _machine_vars["curDeadlines"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_curDeadlines";
    _var_label.innerHTML = "GenericTimersMC.curDeadlines";
    _state_view_vars.appendChild(_var_label);
    _state_view_vars.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._get_pitman_direction();
    _var_div.id = "_var_pitman_direction";
    _machine_vars["pitman_direction"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_pitman_direction";
    _var_label.innerHTML = "PitmanController_TIME_MC_v4.pitman_direction";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_BLINK_DIRECTION();
    _var_div.id = "_var_BLINK_DIRECTION";
    _machine_vars["BLINK_DIRECTION"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_BLINK_DIRECTION";
    _var_label.innerHTML = "BlinkLamps_v3.BLINK_DIRECTION";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_LAMP_STATUS();
    _var_div.id = "_var_LAMP_STATUS";
    _machine_vars["LAMP_STATUS"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_LAMP_STATUS";
    _var_label.innerHTML = "BlinkLamps_v3.LAMP_STATUS";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_lamp_on();
    _var_div.id = "_var_lamp_on";
    _machine_vars["lamp_on"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_lamp_on";
    _var_label.innerHTML = "BlinkLamps_v3.lamp_on";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_lamp_off();
    _var_div.id = "_var_lamp_off";
    _machine_vars["lamp_off"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_lamp_off";
    _var_label.innerHTML = "BlinkLamps_v3.lamp_off";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_BLINK_CYCLE_COUNTER();
    _var_div.id = "_var_BLINK_CYCLE_COUNTER";
    _machine_vars["BLINK_CYCLE_COUNTER"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_BLINK_CYCLE_COUNTER";
    _var_label.innerHTML = "BlinkLamps_v3.BLINK_CYCLE_COUNTER";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get_cycleMaxLampStatus();
    _var_div.id = "_var_cycleMaxLampStatus";
    _machine_vars["cycleMaxLampStatus"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_cycleMaxLampStatus";
    _var_label.innerHTML = "BlinkLamps_v3.cycleMaxLampStatus";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get_PITMAN_DIRECTION_BLINKING();
    _var_div.id = "_var_PITMAN_DIRECTION_BLINKING";
    _machine_vars["PITMAN_DIRECTION_BLINKING"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_PITMAN_DIRECTION_BLINKING";
    _var_label.innerHTML = "Sensors.PITMAN_DIRECTION_BLINKING";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get_PITMAN_TIP_BLINKING();
    _var_div.id = "_var_PITMAN_TIP_BLINKING";
    _machine_vars["PITMAN_TIP_BLINKING"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_PITMAN_TIP_BLINKING";
    _var_label.innerHTML = "Sensors.PITMAN_TIP_BLINKING";
    _state_view_consts.appendChild(_var_label);
    _state_view_consts.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["BlinkLamps_v3"]()._get__DIRECTIONS();
    _var_div.id = "_var_DIRECTIONS";
    _machine_vars["DIRECTIONS"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_DIRECTIONS";
    _var_label.innerHTML = "BlinkLamps_v3.DIRECTIONS";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get__SWITCH_STATUS();
    _var_div.id = "_var_SWITCH_STATUS";
    _machine_vars["SWITCH_STATUS"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_SWITCH_STATUS";
    _var_label.innerHTML = "Sensors.SWITCH_STATUS";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get__PITMAN_POSITION();
    _var_div.id = "_var_PITMAN_POSITION";
    _machine_vars["PITMAN_POSITION"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_PITMAN_POSITION";
    _var_label.innerHTML = "Sensors.PITMAN_POSITION";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["Sensors"]()._get__KEY_STATE();
    _var_div.id = "_var_KEY_STATE";
    _machine_vars["KEY_STATE"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_KEY_STATE";
    _var_label.innerHTML = "Sensors.KEY_STATE";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["GenericTimersMC"]()._get__TIMERS();
    _var_div.id = "_var_TIMERS";
    _machine_vars["TIMERS"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_var_TIMERS";
    _var_label.innerHTML = "GenericTimersMC.TIMERS";
    _state_view_sets.appendChild(_var_label);
    _state_view_sets.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._check_inv_1();
    _var_div.id = "_check_inv_1";
    _machine_vars["_check_inv_1"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_1";
    _var_label.innerHTML = "hazardWarningSwitchOn=switch_on=>active_blinkers=BLINK_DIRECTION";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._check_inv_2();
    _var_div.id = "_check_inv_2";
    _machine_vars["_check_inv_2"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_2";
    _var_label.innerHTML = "hazardWarningSwitchOn=switch_off&remaining_blinks=-1=>active_blinkers={pitman_direction(pitmanArmUpDown)}";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._check_inv_3();
    _var_div.id = "_check_inv_3";
    _machine_vars["_check_inv_3"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_3";
    _var_label.innerHTML = "pitmanArmUpDown:PITMAN_DIRECTION_BLINKING&engineOn=TRUE=>{pitman_direction(pitmanArmUpDown)}<:active_blinkers";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._check_inv_4();
    _var_div.id = "_check_inv_4";
    _machine_vars["_check_inv_4"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_4";
    _var_label.innerHTML = "engineOn=FALSE&hazardWarningSwitchOn=switch_off=>active_blinkers={}";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._check_inv_5();
    _var_div.id = "_check_inv_5";
    _machine_vars["_check_inv_5"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_5";
    _var_label.innerHTML = "hazardWarningSwitchOn=switch_on⇒remaining_blinks=-1";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);
    _var_div = document.createElement("div");
    _var_div.innerHTML = _included_machines["PitmanController_TIME_MC_v4"]()._check_inv_6();
    _var_div.id = "_check_inv_6";
    _machine_vars["_check_inv_6"] = _var_div;
    _var_label = document.createElement("label");
    _var_label.htmlFor = "_check_inv_6";
    _var_label.innerHTML = "pitmanArmUpDown∈PITMAN_DIRECTION_BLINKING&engineOn=TRUE⇒remaining_blinks=-1";
    _state_view_invariant.appendChild(_var_label);
    _state_view_invariant.appendChild(_var_div);

    function updateVisuals () {
      _svg_vars["key-inserted"].setAttribute("visibility", (_machine._Sensors._get_keyState().equal(new KEY_STATE(enum_KEY_STATE.NoKeyInserted)).booleanValue() ? new BString("visible") : new BString("hidden")).getValue());
      _svg_vars["circle-PitmanUpward"].setAttribute("stroke-opacity", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7)).booleanValue() ? new BString("1") : (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5)).booleanValue() ? new BString("0.6") : new BString("0.5"))).getValue());
      _svg_vars["back-window"].setAttribute("fill", (_machine._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue() ? new BString("#f2f2f2") : new BString("white")).getValue());
      _svg_vars["front-window"].setAttribute("fill", (_machine._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue() ? new BString("#f2f2f2") : new BString("white")).getValue());
      _svg_vars["PitmanNeutral"].setAttribute("fill-opacity", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral)).booleanValue() ? new BString("1") : new BString("0.2")).getValue());
      _svg_vars["B-right"].setAttribute("stroke-opacity", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink)).booleanValue() ? new BString("0.5") : new BString("1")).getValue());
      _svg_vars["key-on-position"].setAttribute("visibility", (new BBoolean(_machine._Sensors._get_keyState().equal(new KEY_STATE(enum_KEY_STATE.NoKeyInserted)).booleanValue() || _machine._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue()).booleanValue() ? new BString("hidden") : new BString("visible")).getValue());
      _svg_vars["A-left"].setAttribute("stroke-opacity", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink)).booleanValue() ? new BString("0.5") : new BString("1")).getValue());
      _svg_vars["circle-PitmanUpward"].setAttribute("stroke-width", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7)).booleanValue() ? new BString("1") : (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5)).booleanValue() ? new BString("0.6") : new BString("0.565"))).getValue());
      _svg_vars["circle-PitmanDownward"].setAttribute("stroke-opacity", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7)).booleanValue() ? new BString("1") : (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5)).booleanValue() ? new BString("0.6") : new BString("0.5"))).getValue());
      _svg_vars["A-right"].setAttribute("fill", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink)).booleanValue() ? (_machine._BlinkLamps_v3._get_blinkRight().equal(_machine._BlinkLamps_v3._get_lamp_off()).booleanValue() ? new BString("#ffe6cc") : new BString("orange")) : new BString("white")).getValue());
      _svg_vars["A-right"].setAttribute("stroke-opacity", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink)).booleanValue() ? new BString("0.5") : new BString("1")).getValue());
      _svg_vars["PitmanDownward"].setAttribute("fill-opacity", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7)).booleanValue() ? new BString("1") : (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5)).booleanValue() ? new BString("0.85") : new BString("0.2"))).getValue());
      _svg_vars["warningLight"].setAttribute("fill-opacity", (_machine._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on)).booleanValue() ? new BString("0.7") : new BString("0.05")).getValue());
      _svg_vars["car_outline"].setAttribute("stroke-opacity", (_machine._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue() ? new BString("1.0") : new BString("0.5")).getValue());
      _svg_vars["C-left"].setAttribute("fill", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink)).booleanValue() ? (_machine._BlinkLamps_v3._get_blinkLeft().equal(_machine._BlinkLamps_v3._get_lamp_off()).booleanValue() ? new BString("#ffe6cc") : new BString("orange")) : new BString("white")).getValue());
      _svg_vars["B-right"].setAttribute("fill", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink)).booleanValue() ? (_machine._BlinkLamps_v3._get_blinkRight().equal(_machine._BlinkLamps_v3._get_lamp_off()).booleanValue() ? new BString("#ffe6cc") : new BString("orange")) : new BString("white")).getValue());
      _svg_vars["B-left"].setAttribute("stroke-opacity", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink)).booleanValue() ? new BString("0.5") : new BString("1")).getValue());
      _svg_vars["key-on-text"].setAttribute("fill", (new BBoolean(_machine._Sensors._get_keyState().equal(new KEY_STATE(enum_KEY_STATE.NoKeyInserted)).booleanValue() || _machine._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue()).booleanValue() ? new BString("#f2f2f2") : new BString("#ccffcc")).getValue());
      _svg_vars["A-left"].setAttribute("fill", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink)).booleanValue() ? (_machine._BlinkLamps_v3._get_blinkLeft().equal(_machine._BlinkLamps_v3._get_lamp_off()).booleanValue() ? new BString("#ffe6cc") : new BString("orange")) : new BString("white")).getValue());
      _svg_vars["engine-start"].setAttribute("visibility", (new BBoolean(_machine._Sensors._get_keyState().equal(new KEY_STATE(enum_KEY_STATE.NoKeyInserted)).booleanValue() || _machine._Sensors._get_engineOn().equal(new BBoolean(false)).booleanValue()).booleanValue() ? new BString("hidden") : new BString("visible")).getValue());
      _svg_vars["B-left"].setAttribute("fill", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink)).booleanValue() ? (_machine._BlinkLamps_v3._get_blinkLeft().equal(_machine._BlinkLamps_v3._get_lamp_off()).booleanValue() ? new BString("#ffe6cc") : new BString("orange")) : new BString("white")).getValue());
      _svg_vars["PitmanUpward"].setAttribute("fill-opacity", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7)).booleanValue() ? new BString("1") : (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5)).booleanValue() ? new BString("0.85") : new BString("0.2"))).getValue());
      _svg_vars["timer-text"].setAttribute("text", new BString("").getValue());
      _svg_vars["C-right"].setAttribute("fill", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink)).booleanValue() ? (_machine._BlinkLamps_v3._get_blinkRight().equal(_machine._BlinkLamps_v3._get_lamp_off()).booleanValue() ? new BString("#ffe6cc") : new BString("orange")) : new BString("white")).getValue());
      _svg_vars["C-right"].setAttribute("stroke-opacity", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink)).booleanValue() ? new BString("0.5") : new BString("1")).getValue());
      _svg_vars["C-left"].setAttribute("stroke-opacity", (_machine._BlinkLamps_v3._get_active_blinkers().elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink)).booleanValue() ? new BString("0.5") : new BString("1")).getValue());
      _svg_vars["circle-PitmanDownward"].setAttribute("stroke-width", (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7)).booleanValue() ? new BString("1") : (_machine._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5)).booleanValue() ? new BString("0.6") : new BString("0.565"))).getValue());
      _machine_vars["active_blinkers"].innerHTML = _included_machines["BlinkLamps_v3"]()._get_active_blinkers();
      _machine_vars["remaining_blinks"].innerHTML = _included_machines["BlinkLamps_v3"]()._get_remaining_blinks();
      _machine_vars["onCycle"].innerHTML = _included_machines["BlinkLamps_v3"]()._get_onCycle();
      _machine_vars["blinkLeft"].innerHTML = _included_machines["BlinkLamps_v3"]()._get_blinkLeft();
      _machine_vars["blinkRight"].innerHTML = _included_machines["BlinkLamps_v3"]()._get_blinkRight();
      _machine_vars["hazardWarningSwitchOn"].innerHTML = _included_machines["Sensors"]()._get_hazardWarningSwitchOn();
      _machine_vars["pitmanArmUpDown"].innerHTML = _included_machines["Sensors"]()._get_pitmanArmUpDown();
      _machine_vars["keyState"].innerHTML = _included_machines["Sensors"]()._get_keyState();
      _machine_vars["engineOn"].innerHTML = _included_machines["Sensors"]()._get_engineOn();
      _machine_vars["curDeadlines"].innerHTML = _included_machines["GenericTimersMC"]()._get_curDeadlines();
      for (let i = 1; i <= 6; i++) {
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
    _machine_events["ENV_Turn_EngineOff"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["ENV_Turn_EngineOff"].style.gridColumn="-1";
    _machine_events["ENV_Turn_EngineOff"].innerHTML = "ENV_Turn_EngineOff";
    _machine_events["ENV_Turn_EngineOff"].parameterNames = [];
    _machine_events["ENV_Turn_EngineOff"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Turn_EngineOff"] == null ?? true) {
          transition = _machine._tr_ENV_Turn_EngineOff();
          _transition_list[index]["ENV_Turn_EngineOff"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Turn_EngineOff"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Turn_EngineOff is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Turn_EngineOff(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Turn_EngineOff(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Turn_EngineOff", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Turn_EngineOff");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Turn_EngineOff"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Turn_EngineOff"].disabled = true;
            }
            createOptionList("ENV_Turn_EngineOff", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["ENV_Turn_EngineOff"]);

    _svg_events["engine-start"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("engine-start");
    _svg_events["engine-start"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Turn_EngineOff"] == null ?? true) {
          transition = _machine._tr_ENV_Turn_EngineOff();
          _transition_list[index]["ENV_Turn_EngineOff"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Turn_EngineOff"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Turn_EngineOff is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Turn_EngineOff(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Turn_EngineOff(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Turn_EngineOff", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Turn_EngineOff");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Turn_EngineOff"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Turn_EngineOff"].disabled = true;
            }
            createOptionList("ENV_Turn_EngineOff", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["ENV_Hazard_blinking"] = document.createElement("button");
    var newSwitchPos_label = document.createElement("label")
    newSwitchPos_label.textContent = "newSwitchPos:";
    newSwitchPos_label.htmlFor="newSwitchPos";
    _param_div.appendChild(newSwitchPos_label);
    var newSwitchPos = document.createElement("input");
    newSwitchPos.id="newSwitchPos";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="ENV_Hazard_blinking_newSwitchPos_datalist";
    _param_div.appendChild(_param_datalist);
    newSwitchPos.setAttribute("list", "ENV_Hazard_blinking_newSwitchPos_datalist");
    newSwitchPos.getValue = function() {return this.value == "" ? null : SWITCH_STATUS["get_" + this.value]()}
    newSwitchPos.setValue = function(value) {this.value = value}
    newSwitchPos.parseValue = function(value) {return value == "" ? null : SWITCH_STATUS["get_" + value]()}
    _param_div.appendChild(newSwitchPos);
    _machine_events["ENV_Hazard_blinking"]["newSwitchPos"] = newSwitchPos;

    _operations_view.appendChild(_param_div);


    _machine_events["ENV_Hazard_blinking"].style.gridColumn="-1";
    _machine_events["ENV_Hazard_blinking"].innerHTML = "ENV_Hazard_blinking";
    _machine_events["ENV_Hazard_blinking"].parameterNames = ["newSwitchPos", ];
    _machine_events["ENV_Hazard_blinking"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Hazard_blinking"] == null ?? true) {
          transition = _machine._tr_ENV_Hazard_blinking();
          _transition_list[index]["ENV_Hazard_blinking"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Hazard_blinking"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Hazard_blinking is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["newSwitchPos"].map(function(e, i) {
                        _machine_events["ENV_Hazard_blinking"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.newSwitchPos ?? _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event ENV_Hazard_blinking!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event ENV_Hazard_blinking!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.newSwitchPos ?? _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue(), ];
        var returnValue = _machine.ENV_Hazard_blinking(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Hazard_blinking(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["newSwitchPos"] = _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Hazard_blinking", params: parametersJSON});
        updateVisuals();
        _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].setValue("")
        triggerSimulationOnInteraction("ENV_Hazard_blinking");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.newSwitchPos ?? _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Hazard_blinking"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Hazard_blinking"].disabled = true;
            }
            createOptionList("ENV_Hazard_blinking", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["ENV_Hazard_blinking"]);

    _svg_events["warningLightOuter"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("warningLightOuter");
    _svg_events["warningLightOuter"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Hazard_blinking"] == null ?? true) {
          transition = _machine._tr_ENV_Hazard_blinking();
          _transition_list[index]["ENV_Hazard_blinking"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Hazard_blinking"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Hazard_blinking is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["newSwitchPos"].map(function(e, i) {
                        _machine_events["ENV_Hazard_blinking"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.newSwitchPos ?? _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event ENV_Hazard_blinking!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event ENV_Hazard_blinking!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.newSwitchPos ?? _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue(), ];
        var returnValue = _machine.ENV_Hazard_blinking(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Hazard_blinking(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["newSwitchPos"] = _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Hazard_blinking", params: parametersJSON});
        updateVisuals();
        _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].setValue("")
        triggerSimulationOnInteraction("ENV_Hazard_blinking");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.newSwitchPos ?? _machine_events["ENV_Hazard_blinking"]["newSwitchPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Hazard_blinking"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Hazard_blinking"].disabled = true;
            }
            createOptionList("ENV_Hazard_blinking", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["ENV_Pitman_Reset_to_Neutral"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["ENV_Pitman_Reset_to_Neutral"].style.gridColumn="-1";
    _machine_events["ENV_Pitman_Reset_to_Neutral"].innerHTML = "ENV_Pitman_Reset_to_Neutral";
    _machine_events["ENV_Pitman_Reset_to_Neutral"].parameterNames = [];
    _machine_events["ENV_Pitman_Reset_to_Neutral"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Pitman_Reset_to_Neutral"] == null ?? true) {
          transition = _machine._tr_ENV_Pitman_Reset_to_Neutral();
          _transition_list[index]["ENV_Pitman_Reset_to_Neutral"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Pitman_Reset_to_Neutral"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Pitman_Reset_to_Neutral is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Pitman_Reset_to_Neutral(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Pitman_Reset_to_Neutral(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Pitman_Reset_to_Neutral", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Pitman_Reset_to_Neutral");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Pitman_Reset_to_Neutral"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Pitman_Reset_to_Neutral"].disabled = true;
            }
            createOptionList("ENV_Pitman_Reset_to_Neutral", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["ENV_Pitman_Reset_to_Neutral"]);

    _svg_events["PitmanNeutral"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("PitmanNeutral");
    _svg_events["PitmanNeutral"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Pitman_Reset_to_Neutral"] == null ?? true) {
          transition = _machine._tr_ENV_Pitman_Reset_to_Neutral();
          _transition_list[index]["ENV_Pitman_Reset_to_Neutral"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Pitman_Reset_to_Neutral"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Pitman_Reset_to_Neutral is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Pitman_Reset_to_Neutral(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Pitman_Reset_to_Neutral(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Pitman_Reset_to_Neutral", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Pitman_Reset_to_Neutral");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Pitman_Reset_to_Neutral"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Pitman_Reset_to_Neutral"].disabled = true;
            }
            createOptionList("ENV_Pitman_Reset_to_Neutral", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["RTIME_Nothing"] = document.createElement("button");
    var delta_label = document.createElement("label")
    delta_label.textContent = "delta:";
    delta_label.htmlFor="delta";
    _param_div.appendChild(delta_label);
    var delta = document.createElement("input");
    delta.id="delta";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="RTIME_Nothing_delta_datalist";
    _param_div.appendChild(_param_datalist);
    delta.setAttribute("list", "RTIME_Nothing_delta_datalist");
    delta.getValue = function() {return new BInteger(parseInt(this.value))}
    delta.setValue = function(value) {this.value = value}
    delta.parseValue = function(value) {return new BInteger(parseInt(value))}
    _param_div.appendChild(delta);
    _machine_events["RTIME_Nothing"]["delta"] = delta;
    var newOnCycle_label = document.createElement("label")
    newOnCycle_label.textContent = "newOnCycle:";
    newOnCycle_label.htmlFor="newOnCycle";
    _param_div.appendChild(newOnCycle_label);
    var newOnCycle = document.createElement("input");
    newOnCycle.id="newOnCycle";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="RTIME_Nothing_newOnCycle_datalist";
    _param_div.appendChild(_param_datalist);
    newOnCycle.setAttribute("list", "RTIME_Nothing_newOnCycle_datalist");
    newOnCycle.getValue = function() {return new BBoolean(this.value == "true")}
    newOnCycle.setValue = function(value) {this.value = value}
    newOnCycle.parseValue = function(value) {return new BBoolean(value == "true")}
    _param_div.appendChild(newOnCycle);
    _machine_events["RTIME_Nothing"]["newOnCycle"] = newOnCycle;

    _operations_view.appendChild(_param_div);


    _machine_events["RTIME_Nothing"].style.gridColumn="-1";
    _machine_events["RTIME_Nothing"].innerHTML = "RTIME_Nothing";
    _machine_events["RTIME_Nothing"].parameterNames = ["delta", "newOnCycle", ];
    _machine_events["RTIME_Nothing"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_Nothing"] == null ?? true) {
          transition = _machine._tr_RTIME_Nothing();
          _transition_list[index]["RTIME_Nothing"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_Nothing"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_Nothing is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_Nothing"]["delta"].getValue() == null && _machine_events["RTIME_Nothing"]["newOnCycle"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta", "newOnCycle"].map(function(e, i) {
                        _machine_events["RTIME_Nothing"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_Nothing"]["delta"].getValue(), parameters?.newOnCycle ?? _machine_events["RTIME_Nothing"]["newOnCycle"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_Nothing!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_Nothing!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_Nothing"]["delta"].getValue(), parameters?.newOnCycle ?? _machine_events["RTIME_Nothing"]["newOnCycle"].getValue(), ];
        var returnValue = _machine.RTIME_Nothing(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_Nothing(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_Nothing"]["delta"].getValue().toString();
        parametersJSON["newOnCycle"] = _machine_events["RTIME_Nothing"]["newOnCycle"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_Nothing", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_Nothing"]["delta"].setValue(""); _machine_events["RTIME_Nothing"]["newOnCycle"].setValue("")
        triggerSimulationOnInteraction("RTIME_Nothing");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_Nothing"]["delta"].getValue(), parameters?.newOnCycle ?? _machine_events["RTIME_Nothing"]["newOnCycle"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_Nothing"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_Nothing"].disabled = true;
            }
            createOptionList("RTIME_Nothing", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["RTIME_Nothing"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["ENV_Turn_EngineOn"] = document.createElement("button");
    _operations_view.appendChild(_param_div);


    _machine_events["ENV_Turn_EngineOn"].style.gridColumn="-1";
    _machine_events["ENV_Turn_EngineOn"].innerHTML = "ENV_Turn_EngineOn";
    _machine_events["ENV_Turn_EngineOn"].parameterNames = [];
    _machine_events["ENV_Turn_EngineOn"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Turn_EngineOn"] == null ?? true) {
          transition = _machine._tr_ENV_Turn_EngineOn();
          _transition_list[index]["ENV_Turn_EngineOn"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Turn_EngineOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Turn_EngineOn is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Turn_EngineOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Turn_EngineOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Turn_EngineOn", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Turn_EngineOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Turn_EngineOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Turn_EngineOn"].disabled = true;
            }
            createOptionList("ENV_Turn_EngineOn", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["ENV_Turn_EngineOn"]);

    _svg_events["front-window"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("front-window");
    _svg_events["front-window"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Turn_EngineOn"] == null ?? true) {
          transition = _machine._tr_ENV_Turn_EngineOn();
          _transition_list[index]["ENV_Turn_EngineOn"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Turn_EngineOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Turn_EngineOn is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Turn_EngineOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Turn_EngineOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Turn_EngineOn", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Turn_EngineOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Turn_EngineOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Turn_EngineOn"].disabled = true;
            }
            createOptionList("ENV_Turn_EngineOn", transition);
        }
        alert(error.message);
      }
    }

    _svg_events["key-on-position"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("key-on-position");
    _svg_events["key-on-position"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Turn_EngineOn"] == null ?? true) {
          transition = _machine._tr_ENV_Turn_EngineOn();
          _transition_list[index]["ENV_Turn_EngineOn"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Turn_EngineOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Turn_EngineOn is not enabled!");
            return;
        }
      }
      try {
        var parameters = [];
        var returnValue = _machine.ENV_Turn_EngineOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Turn_EngineOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Turn_EngineOn", params: parametersJSON});
        updateVisuals();
        triggerSimulationOnInteraction("ENV_Turn_EngineOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Turn_EngineOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Turn_EngineOn"].disabled = true;
            }
            createOptionList("ENV_Turn_EngineOn", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["ENV_Pitman_Tip_blinking_start"] = document.createElement("button");
    var newPos_label = document.createElement("label")
    newPos_label.textContent = "newPos:";
    newPos_label.htmlFor="newPos";
    _param_div.appendChild(newPos_label);
    var newPos = document.createElement("input");
    newPos.id="newPos";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="ENV_Pitman_Tip_blinking_start_newPos_datalist";
    _param_div.appendChild(_param_datalist);
    newPos.setAttribute("list", "ENV_Pitman_Tip_blinking_start_newPos_datalist");
    newPos.getValue = function() {return this.value == "" ? null : PITMAN_POSITION["get_" + this.value]()}
    newPos.setValue = function(value) {this.value = value}
    newPos.parseValue = function(value) {return value == "" ? null : PITMAN_POSITION["get_" + value]()}
    _param_div.appendChild(newPos);
    _machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"] = newPos;

    _operations_view.appendChild(_param_div);


    _machine_events["ENV_Pitman_Tip_blinking_start"].style.gridColumn="-1";
    _machine_events["ENV_Pitman_Tip_blinking_start"].innerHTML = "ENV_Pitman_Tip_blinking_start";
    _machine_events["ENV_Pitman_Tip_blinking_start"].parameterNames = ["newPos", ];
    _machine_events["ENV_Pitman_Tip_blinking_start"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Pitman_Tip_blinking_start"] == null ?? true) {
          transition = _machine._tr_ENV_Pitman_Tip_blinking_start();
          _transition_list[index]["ENV_Pitman_Tip_blinking_start"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Pitman_Tip_blinking_start"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Pitman_Tip_blinking_start is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["newPos"].map(function(e, i) {
                        _machine_events["ENV_Pitman_Tip_blinking_start"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event ENV_Pitman_Tip_blinking_start!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event ENV_Pitman_Tip_blinking_start!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.newPos ?? _machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"].getValue(), ];
        var returnValue = _machine.ENV_Pitman_Tip_blinking_start(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Pitman_Tip_blinking_start(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["newPos"] = _machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Pitman_Tip_blinking_start", params: parametersJSON});
        updateVisuals();
        _machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"].setValue("")
        triggerSimulationOnInteraction("ENV_Pitman_Tip_blinking_start");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_Tip_blinking_start"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Pitman_Tip_blinking_start"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Pitman_Tip_blinking_start"].disabled = true;
            }
            createOptionList("ENV_Pitman_Tip_blinking_start", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["ENV_Pitman_Tip_blinking_start"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["RTIME_BlinkerOff"] = document.createElement("button");
    var delta_label = document.createElement("label")
    delta_label.textContent = "delta:";
    delta_label.htmlFor="delta";
    _param_div.appendChild(delta_label);
    var delta = document.createElement("input");
    delta.id="delta";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="RTIME_BlinkerOff_delta_datalist";
    _param_div.appendChild(_param_datalist);
    delta.setAttribute("list", "RTIME_BlinkerOff_delta_datalist");
    delta.getValue = function() {return new BInteger(parseInt(this.value))}
    delta.setValue = function(value) {this.value = value}
    delta.parseValue = function(value) {return new BInteger(parseInt(value))}
    _param_div.appendChild(delta);
    _machine_events["RTIME_BlinkerOff"]["delta"] = delta;

    _operations_view.appendChild(_param_div);


    _machine_events["RTIME_BlinkerOff"].style.gridColumn="-1";
    _machine_events["RTIME_BlinkerOff"].innerHTML = "RTIME_BlinkerOff";
    _machine_events["RTIME_BlinkerOff"].parameterNames = ["delta", ];
    _machine_events["RTIME_BlinkerOff"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_BlinkerOff"] == null ?? true) {
          transition = _machine._tr_RTIME_BlinkerOff();
          _transition_list[index]["RTIME_BlinkerOff"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_BlinkerOff"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_BlinkerOff is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_BlinkerOff"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_BlinkerOff"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOff"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_BlinkerOff!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_BlinkerOff!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_BlinkerOff"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_BlinkerOff(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_BlinkerOff(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_BlinkerOff"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_BlinkerOff", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_BlinkerOff"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_BlinkerOff");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOff"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_BlinkerOff"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_BlinkerOff"].disabled = true;
            }
            createOptionList("RTIME_BlinkerOff", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["RTIME_BlinkerOff"]);

    _svg_events["C-right"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("C-right");
    _svg_events["C-right"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_BlinkerOff"] == null ?? true) {
          transition = _machine._tr_RTIME_BlinkerOff();
          _transition_list[index]["RTIME_BlinkerOff"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_BlinkerOff"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_BlinkerOff is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_BlinkerOff"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_BlinkerOff"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOff"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_BlinkerOff!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_BlinkerOff!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_BlinkerOff"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_BlinkerOff(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_BlinkerOff(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_BlinkerOff"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_BlinkerOff", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_BlinkerOff"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_BlinkerOff");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOff"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_BlinkerOff"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_BlinkerOff"].disabled = true;
            }
            createOptionList("RTIME_BlinkerOff", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["ENV_Pitman_DirectionBlinking"] = document.createElement("button");
    var newPos_label = document.createElement("label")
    newPos_label.textContent = "newPos:";
    newPos_label.htmlFor="newPos";
    _param_div.appendChild(newPos_label);
    var newPos = document.createElement("input");
    newPos.id="newPos";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="ENV_Pitman_DirectionBlinking_newPos_datalist";
    _param_div.appendChild(_param_datalist);
    newPos.setAttribute("list", "ENV_Pitman_DirectionBlinking_newPos_datalist");
    newPos.getValue = function() {return this.value == "" ? null : PITMAN_POSITION["get_" + this.value]()}
    newPos.setValue = function(value) {this.value = value}
    newPos.parseValue = function(value) {return value == "" ? null : PITMAN_POSITION["get_" + value]()}
    _param_div.appendChild(newPos);
    _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"] = newPos;

    _operations_view.appendChild(_param_div);


    _machine_events["ENV_Pitman_DirectionBlinking"].style.gridColumn="-1";
    _machine_events["ENV_Pitman_DirectionBlinking"].innerHTML = "ENV_Pitman_DirectionBlinking";
    _machine_events["ENV_Pitman_DirectionBlinking"].parameterNames = ["newPos", ];
    _machine_events["ENV_Pitman_DirectionBlinking"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Pitman_DirectionBlinking"] == null ?? true) {
          transition = _machine._tr_ENV_Pitman_DirectionBlinking();
          _transition_list[index]["ENV_Pitman_DirectionBlinking"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Pitman_DirectionBlinking"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Pitman_DirectionBlinking is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["newPos"].map(function(e, i) {
                        _machine_events["ENV_Pitman_DirectionBlinking"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event ENV_Pitman_DirectionBlinking!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event ENV_Pitman_DirectionBlinking!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ];
        var returnValue = _machine.ENV_Pitman_DirectionBlinking(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Pitman_DirectionBlinking(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["newPos"] = _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Pitman_DirectionBlinking", params: parametersJSON});
        updateVisuals();
        _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].setValue("")
        triggerSimulationOnInteraction("ENV_Pitman_DirectionBlinking");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Pitman_DirectionBlinking"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Pitman_DirectionBlinking"].disabled = true;
            }
            createOptionList("ENV_Pitman_DirectionBlinking", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["ENV_Pitman_DirectionBlinking"]);

    _svg_events["PitmanUpward"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("PitmanUpward");
    _svg_events["PitmanUpward"].onclick = function() {
      var parameters = {
        newPos: new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7),
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Pitman_DirectionBlinking"] == null ?? true) {
          transition = _machine._tr_ENV_Pitman_DirectionBlinking();
          _transition_list[index]["ENV_Pitman_DirectionBlinking"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Pitman_DirectionBlinking"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Pitman_DirectionBlinking is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["newPos"].map(function(e, i) {
                        _machine_events["ENV_Pitman_DirectionBlinking"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event ENV_Pitman_DirectionBlinking!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event ENV_Pitman_DirectionBlinking!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ];
        var returnValue = _machine.ENV_Pitman_DirectionBlinking(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Pitman_DirectionBlinking(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["newPos"] = _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Pitman_DirectionBlinking", params: parametersJSON});
        updateVisuals();
        _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].setValue("")
        triggerSimulationOnInteraction("ENV_Pitman_DirectionBlinking");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Pitman_DirectionBlinking"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Pitman_DirectionBlinking"].disabled = true;
            }
            createOptionList("ENV_Pitman_DirectionBlinking", transition);
        }
        alert(error.message);
      }
    }

    _svg_events["PitmanDownward"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("PitmanDownward");
    _svg_events["PitmanDownward"].onclick = function() {
      var parameters = {
        newPos: new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7),
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["ENV_Pitman_DirectionBlinking"] == null ?? true) {
          transition = _machine._tr_ENV_Pitman_DirectionBlinking();
          _transition_list[index]["ENV_Pitman_DirectionBlinking"] = transition;
      } else {
          transition = _transition_list[index]["ENV_Pitman_DirectionBlinking"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event ENV_Pitman_DirectionBlinking is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["newPos"].map(function(e, i) {
                        _machine_events["ENV_Pitman_DirectionBlinking"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event ENV_Pitman_DirectionBlinking!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event ENV_Pitman_DirectionBlinking!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ];
        var returnValue = _machine.ENV_Pitman_DirectionBlinking(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("ENV_Pitman_DirectionBlinking(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["newPos"] = _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "ENV_Pitman_DirectionBlinking", params: parametersJSON});
        updateVisuals();
        _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].setValue("")
        triggerSimulationOnInteraction("ENV_Pitman_DirectionBlinking");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.newPos ?? _machine_events["ENV_Pitman_DirectionBlinking"]["newPos"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["ENV_Pitman_DirectionBlinking"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["ENV_Pitman_DirectionBlinking"].disabled = true;
            }
            createOptionList("ENV_Pitman_DirectionBlinking", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["RTIME_Tip_blinking_Timeout"] = document.createElement("button");
    var delta_label = document.createElement("label")
    delta_label.textContent = "delta:";
    delta_label.htmlFor="delta";
    _param_div.appendChild(delta_label);
    var delta = document.createElement("input");
    delta.id="delta";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="RTIME_Tip_blinking_Timeout_delta_datalist";
    _param_div.appendChild(_param_datalist);
    delta.setAttribute("list", "RTIME_Tip_blinking_Timeout_delta_datalist");
    delta.getValue = function() {return new BInteger(parseInt(this.value))}
    delta.setValue = function(value) {this.value = value}
    delta.parseValue = function(value) {return new BInteger(parseInt(value))}
    _param_div.appendChild(delta);
    _machine_events["RTIME_Tip_blinking_Timeout"]["delta"] = delta;

    _operations_view.appendChild(_param_div);


    _machine_events["RTIME_Tip_blinking_Timeout"].style.gridColumn="-1";
    _machine_events["RTIME_Tip_blinking_Timeout"].innerHTML = "RTIME_Tip_blinking_Timeout";
    _machine_events["RTIME_Tip_blinking_Timeout"].parameterNames = ["delta", ];
    _machine_events["RTIME_Tip_blinking_Timeout"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_Tip_blinking_Timeout"] == null ?? true) {
          transition = _machine._tr_RTIME_Tip_blinking_Timeout();
          _transition_list[index]["RTIME_Tip_blinking_Timeout"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_Tip_blinking_Timeout"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_Tip_blinking_Timeout is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_Tip_blinking_Timeout"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_Tip_blinking_Timeout"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_Tip_blinking_Timeout"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_Tip_blinking_Timeout!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_Tip_blinking_Timeout!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_Tip_blinking_Timeout"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_Tip_blinking_Timeout(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_Tip_blinking_Timeout(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_Tip_blinking_Timeout"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_Tip_blinking_Timeout", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_Tip_blinking_Timeout"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_Tip_blinking_Timeout");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_Tip_blinking_Timeout"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_Tip_blinking_Timeout"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_Tip_blinking_Timeout"].disabled = true;
            }
            createOptionList("RTIME_Tip_blinking_Timeout", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["RTIME_Tip_blinking_Timeout"]);


    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["RTIME_BlinkerOn"] = document.createElement("button");
    var delta_label = document.createElement("label")
    delta_label.textContent = "delta:";
    delta_label.htmlFor="delta";
    _param_div.appendChild(delta_label);
    var delta = document.createElement("input");
    delta.id="delta";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="RTIME_BlinkerOn_delta_datalist";
    _param_div.appendChild(_param_datalist);
    delta.setAttribute("list", "RTIME_BlinkerOn_delta_datalist");
    delta.getValue = function() {return new BInteger(parseInt(this.value))}
    delta.setValue = function(value) {this.value = value}
    delta.parseValue = function(value) {return new BInteger(parseInt(value))}
    _param_div.appendChild(delta);
    _machine_events["RTIME_BlinkerOn"]["delta"] = delta;

    _operations_view.appendChild(_param_div);


    _machine_events["RTIME_BlinkerOn"].style.gridColumn="-1";
    _machine_events["RTIME_BlinkerOn"].innerHTML = "RTIME_BlinkerOn";
    _machine_events["RTIME_BlinkerOn"].parameterNames = ["delta", ];
    _machine_events["RTIME_BlinkerOn"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_BlinkerOn"] == null ?? true) {
          transition = _machine._tr_RTIME_BlinkerOn();
          _transition_list[index]["RTIME_BlinkerOn"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_BlinkerOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_BlinkerOn is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_BlinkerOn"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_BlinkerOn"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_BlinkerOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_BlinkerOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_BlinkerOn"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_BlinkerOn", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_BlinkerOn"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_BlinkerOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_BlinkerOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_BlinkerOn"].disabled = true;
            }
            createOptionList("RTIME_BlinkerOn", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["RTIME_BlinkerOn"]);

    _svg_events["A-left"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("A-left");
    _svg_events["A-left"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_BlinkerOn"] == null ?? true) {
          transition = _machine._tr_RTIME_BlinkerOn();
          _transition_list[index]["RTIME_BlinkerOn"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_BlinkerOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_BlinkerOn is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_BlinkerOn"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_BlinkerOn"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_BlinkerOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_BlinkerOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_BlinkerOn"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_BlinkerOn", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_BlinkerOn"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_BlinkerOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_BlinkerOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_BlinkerOn"].disabled = true;
            }
            createOptionList("RTIME_BlinkerOn", transition);
        }
        alert(error.message);
      }
    }

    _svg_events["B-left"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("B-left");
    _svg_events["B-left"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_BlinkerOn"] == null ?? true) {
          transition = _machine._tr_RTIME_BlinkerOn();
          _transition_list[index]["RTIME_BlinkerOn"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_BlinkerOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_BlinkerOn is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_BlinkerOn"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_BlinkerOn"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_BlinkerOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_BlinkerOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_BlinkerOn"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_BlinkerOn", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_BlinkerOn"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_BlinkerOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_BlinkerOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_BlinkerOn"].disabled = true;
            }
            createOptionList("RTIME_BlinkerOn", transition);
        }
        alert(error.message);
      }
    }

    _svg_events["C-left"] = document.getElementById("LichtUebersicht_v4").contentDocument.getElementById("C-left");
    _svg_events["C-left"].onclick = function() {
      var parameters = {
    };
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_BlinkerOn"] == null ?? true) {
          transition = _machine._tr_RTIME_BlinkerOn();
          _transition_list[index]["RTIME_BlinkerOn"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_BlinkerOn"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_BlinkerOn is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_BlinkerOn"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_BlinkerOn"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_BlinkerOn!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_BlinkerOn(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_BlinkerOn(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_BlinkerOn"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_BlinkerOn", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_BlinkerOn"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_BlinkerOn");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_BlinkerOn"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_BlinkerOn"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_BlinkerOn"].disabled = true;
            }
            createOptionList("RTIME_BlinkerOn", transition);
        }
        alert(error.message);
      }
    }

    _param_div = document.createElement("div");
    _param_div.classList.add("param");
    _machine_events["RTIME_Passes"] = document.createElement("button");
    var delta_label = document.createElement("label")
    delta_label.textContent = "delta:";
    delta_label.htmlFor="delta";
    _param_div.appendChild(delta_label);
    var delta = document.createElement("input");
    delta.id="delta";
    _param_datalist = document.createElement("datalist");
    _param_datalist.id="RTIME_Passes_delta_datalist";
    _param_div.appendChild(_param_datalist);
    delta.setAttribute("list", "RTIME_Passes_delta_datalist");
    delta.getValue = function() {return new BInteger(parseInt(this.value))}
    delta.setValue = function(value) {this.value = value}
    delta.parseValue = function(value) {return new BInteger(parseInt(value))}
    _param_div.appendChild(delta);
    _machine_events["RTIME_Passes"]["delta"] = delta;

    _operations_view.appendChild(_param_div);


    _machine_events["RTIME_Passes"].style.gridColumn="-1";
    _machine_events["RTIME_Passes"].innerHTML = "RTIME_Passes";
    _machine_events["RTIME_Passes"].parameterNames = ["delta", ];
    _machine_events["RTIME_Passes"].onclick = function() {
      var parameters = {};
      let index = [..._history_view.children].indexOf(_history_view.querySelector(".active"));
      var transition;
      if(_transition_list[index]?.["RTIME_Passes"] == null ?? true) {
          transition = _machine._tr_RTIME_Passes();
          _transition_list[index]["RTIME_Passes"] = transition;
      } else {
          transition = _transition_list[index]["RTIME_Passes"];
      }
      if(!(transition instanceof BSet)) {
        if(!transition) {
            alert("Event RTIME_Passes is not enabled!");
            return;
        }
      } else {
          try  {
              if(_machine_events["RTIME_Passes"]["delta"].getValue() == null) {
                  for(let tr of transition) {
                      var parameterTuple = tr;
                      ["delta"].map(function(e, i) {
                        _machine_events["RTIME_Passes"][e].setValue(flattenTuple(parameterTuple)[i]);
                        return null;
                      });
                      break;
                  }
              } else {
                  var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_Passes"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
              }
          } catch {
              alert("Invalid parameters for event RTIME_Passes!\nPossible values are:\n" + transition.toString());
              return;
          }
          if(!transition.elementOf(parameterTuple).booleanValue()) {
              alert("Invalid parameters for event RTIME_Passes!\nPossible values are:\n" + transition.toString());
              return;
          }
      }
      try {
        var parameters = [parameters?.delta ?? _machine_events["RTIME_Passes"]["delta"].getValue(), ];
        var returnValue = _machine.RTIME_Passes(...parameters);
        _description_list = _description_list.slice(0, index + 1);
        _description_list.push("");
        createHistoryElement("RTIME_Passes(" + parameters.join(", ") + ")" + (returnValue? " -> (" + returnValue.toString() + ")": ""), _history_view.querySelector(".active").index + 1);
        let parametersJSON = {};
        parametersJSON["delta"] = _machine_events["RTIME_Passes"]["delta"].getValue().toString();
        _current_trace = _current_trace.slice(0, index + 1)
        _current_trace.push({name: "RTIME_Passes", params: parametersJSON});
        updateVisuals();
        _machine_events["RTIME_Passes"]["delta"].setValue("")
        triggerSimulationOnInteraction("RTIME_Passes");
      } catch (error) {
        if(! error instanceof SelectError) {
            throw error;
        }
        if(transition instanceof BSet) {
            var parameterTuple = [parameters?.delta ?? _machine_events["RTIME_Passes"]["delta"].getValue(), ].reduce((a, e) => new BTuple(a, e));
            transition = transition.difference(new BSet(parameterTuple));
            _transition_list[index]["RTIME_Passes"] = transition;
            if(transition.size().intValue() == 0) {
                _machine_events["RTIME_Passes"].disabled = true;
            }
            createOptionList("RTIME_Passes", transition);
        }
        alert(error.message);
      }
    }

    _operations_view.appendChild(_machine_events["RTIME_Passes"]);



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
            let reader = new FileReader();
	    let data = ""
            reader.onload = function (e) {
              data = e.target.result;
            };
            reader.readAsText(file);
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
          modelName: "PitmanController_TIME_MC_v4"
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
        _machine = new PitmanController_TIME_MC_v4();
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
          modelName: "PitmanController_TIME_MC_v4"
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
