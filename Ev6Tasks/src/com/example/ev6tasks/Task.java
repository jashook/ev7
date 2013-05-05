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
	
	// Helper functions
	
	private void _ctor(float _XValue, float _YValue, int _Color)
	{
		_m_color = _Color;
		
		_m_x = _XValue;
		_m_y = _YValue;
	}

}
