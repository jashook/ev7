////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Author: Jarret Shook
//
// Module: TaskView.java
//
// Modifications:
//
// 9-March-13: Version 1.0: Created
//
// Timeperiod: ev6
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

package com.example.ev6tasks;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

public class Task {
	
	// Member variables
	
	private int _m_color;
	
	private float _m_x;
	private float _m_y;
	
	public enum LOCATIONS { LEFT, TOPLEFT, TOP, TOPRIGHT, RIGHT, BOTTOMRIGHT, BOTTOM, BOTTOMLEFT };
	
	private Task[] _m_locations = new Task[8];
	
	// Constructors
	
	public Task()
	{
		_ctor(0, 0, 0);
	}
	
	public Task(float _XValue, float _YValue, int _Color)
	{
		_ctor(_XValue, _YValue, _Color);
	}
	
	// Member functions
	
	public int get_color() { return _m_color; }
	public float get_x() { return _m_x; }
	public float get_y() { return _m_y; }
	public void set_x(float _NewX) { _m_x = _NewX; }
	public void set_y(float _NewY) { _m_y = _NewY; }
	
	public final Task[] get_neighbors() { return _m_locations; }
	
	public Task get_left() { return _m_locations[LOCATIONS.LEFT.ordinal()]; }
	public Task get_top_left() { return _m_locations[LOCATIONS.TOPLEFT.ordinal()]; }
	public Task get_top() { return _m_locations[LOCATIONS.TOP.ordinal()]; }
	public Task get_top_right() { return _m_locations[LOCATIONS.TOPRIGHT.ordinal()]; }
	public Task get_right() { return _m_locations[LOCATIONS.RIGHT.ordinal()]; }
	public Task get_bottom_right() { return _m_locations[LOCATIONS.BOTTOMRIGHT.ordinal()]; }
	public Task get_bottom() { return _m_locations[LOCATIONS.BOTTOM.ordinal()]; }
	public Task get_bottom_left() { return _m_locations[LOCATIONS.BOTTOMLEFT.ordinal()]; }

	public void set_left(Task _Task) { _m_locations[LOCATIONS.LEFT.ordinal()] = _Task; }
	public void set_top_left(Task _Task) { _m_locations[LOCATIONS.TOPLEFT.ordinal()] = _Task; }
	public void set_top(Task _Task) { _m_locations[LOCATIONS.TOP.ordinal()] = _Task; }
	public void set_top_right(Task _Task) { _m_locations[LOCATIONS.TOPRIGHT.ordinal()] = _Task; }
	public void set_right(Task _Task) { _m_locations[LOCATIONS.RIGHT.ordinal()] = _Task; }
	public void set_bottom_right(Task _Task) { _m_locations[LOCATIONS.BOTTOMRIGHT.ordinal()] = _Task; }
	public void set_bottom(Task _Task) { _m_locations[LOCATIONS.BOTTOM.ordinal()] = _Task; }
	public void set_bottom_left(Task _Task) { _m_locations[LOCATIONS.BOTTOMLEFT.ordinal()] = _Task; }
	
	// Helper functions
	
	private void _ctor(float _XValue, float _YValue, int _Color)
	{
		_m_color = _Color;
		
		_m_x = _XValue;
		_m_y = _YValue;
	}

}
