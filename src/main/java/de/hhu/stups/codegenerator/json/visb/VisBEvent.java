package de.hhu.stups.codegenerator.json.visb;

import de.prob.parser.ast.nodes.predicate.PredicateNode;

import java.util.ArrayList;
import java.util.List;

/**
 * The VisBEvent is designed for the JSON / VisB file
 */
public class VisBEvent {
	private String id;
	private String event;
	private List<String> predicates;
	private List<VisBHover> hovers; // TODO: maybe provide multiple values and allow value to depend on B state
	private List<PredicateNode> predicateNodes;


	/**
	 * These two parameters will be mapped to the id of the corresponding svg element
	 * @param id the id of the svg element, that should be clickable
	 * @param event the event has to be an executable operation of the corresponding B machine
	 * @param predicates the predicates have to be the predicates, which are used for the event above
	 */
	public VisBEvent(String id, String event, List<String> predicates, List<VisBHover> hovers){
		this.id = id;
		this.event = event;
		this.predicates = predicates;
		this.hovers = hovers;
		this.predicateNodes = new ArrayList<>();
	}

	public String getEvent() {
		return event;
	}

	public List<String> getPredicates() {
		return predicates;
	}

	public String getId() {
		return id;
	}

	public List<VisBHover> getHovers() {
		return hovers;
	}

	public List<PredicateNode> getPredicateNodes() {
		return predicateNodes;
	}

	@Override
	public String toString(){
		return "ID: "+id+"\nEVENT: "+event+"\nPREDICATES: "+predicates+"\n";
	}
}
