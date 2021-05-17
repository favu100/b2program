package de.hhu.stups.codegenerator.json.visb;

/**
 * The VisBEvent is designed for the JSON / VisB file
 */
public class VisBHover {
	private String svgID; // id of the object whose attribute is modified upon hover
	private String hoverID;
	private String hoverAttribute;
	private String hoverEnterValue;
	private String hoverLeaveValue;

	public VisBHover(String svgID, String hoverID, String hoverAttribute, String hoverEnterValue, String hoverLeaveValue){
		this.svgID = svgID;
		this.hoverID = hoverID;
		this.hoverAttribute = hoverAttribute;
		this.hoverEnterValue = hoverEnterValue;
		this.hoverLeaveValue = hoverLeaveValue;
	}

	public String getSVGID() {
		return svgID;
	}

	public String getHoverID() {
		return hoverID;
	}

	public String getHoverAttr() {
		return hoverAttribute;
	}
	public String getHoverEnterVal() {
		return hoverEnterValue;
	}
	public String getHoverLeaveVal() {
		return hoverLeaveValue;
	}


	@Override
	public String toString(){
		return "<Hover changing " + hoverID + "." + hoverAttribute+ " upon enter: "+hoverEnterValue+ " leave: " + hoverLeaveValue + ">";
	}
}
