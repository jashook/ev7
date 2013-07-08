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

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import java.util.ArrayList;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


public class TaskView extends View 
{	
	// Constants
	
	private final int INNER_SIZE = 140;
	private final int OUTER_SIZE = 143;
	
	// Member variables
	
	private ArrayList<Task> _m_task_list;
	private int [] _m_colors;
	private Paint _m_paint;
	private View _m_view;
	
	// Constructors
	
	public TaskView(Context _Context) 
	{
		super(_Context);
		
		_ctor();
	}
	
	public TaskView(Context _Context, AttributeSet _Attributes) 
	{
		super(_Context, _Attributes, 0);
		
		_ctor();
	}
	
	public TaskView(Context _Context, AttributeSet _Attributes, int _DefStyle) 
	{
		super(_Context, _Attributes, _DefStyle);
		
		_ctor();
		
	}
	
	// Member Functions
	
	@Override
	public void onDraw(Canvas _Canvas)
	{
		super.onDraw(_Canvas);
		
		for (int _Index = 0, _Size = _m_task_list.size(); _Index < _Size; ++_Index)
		{
			//_m_paint.setColor(_m_colors[_m_task_list.get(_Index).get_color()]);
			
			float x = _m_task_list.get(_Index).get_x();
	      float y = _m_task_list.get(_Index).get_y();

	      _m_paint.setColor(Color.BLACK);
	      _Canvas.drawCircle(x, y, OUTER_SIZE, _m_paint);
	      _m_paint.setColor(Color.WHITE);
	      _Canvas.drawCircle(x, y, INNER_SIZE, _m_paint);

		}
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent _Event)
	{
		
		final int _Action = _Event.getAction();
		
		if (_Action == MotionEvent.ACTION_MOVE) 
		{
			final float _XValue = _Event.getX();
			final float _YValue = _Event.getY();
			
			for (int _Index = 0, _Size = _m_task_list.size(); _Index < _Size; ++_Index)
			{
				if (_is_inside_circle(_m_task_list.get(_Index).get_x(), _m_task_list.get(_Index).get_y(), _XValue, _YValue))
				{
					_m_task_list.get(_Index).set_x(_XValue);
					_m_task_list.get(_Index).set_y(_YValue);
					
					boolean _MoveForward = false;
					boolean _MoveBackward = false;
					
					final Task[] _Tasks = _m_task_list.get(_Index).get_neighbors();
					
					for (int _InnerIndex = 0; _InnerIndex < _Index; ++_InnerIndex)
					{
						if (_is_inside_circle(_m_task_list.get(_InnerIndex).get_x(), _m_task_list.get(_InnerIndex).get_y(), _XValue, _YValue))
						{
							_MoveBackward = true;
						}
						
						if (_MoveBackward)
						{
							_m_task_list.get(_InnerIndex).set_x(_calculate_x(_InnerIndex));
							_m_task_list.get(_InnerIndex).set_x(_calculate_y(_InnerIndex));
						}
					}
					
					for (int _InnerIndex = _Index + 1; _InnerIndex < _Size; ++_InnerIndex)
					{
						if (_is_inside_circle(_m_task_list.get(_InnerIndex).get_x(), _m_task_list.get(_InnerIndex).get_y(), _XValue, _YValue))
						{
							_MoveForward = true;
						}
						
						if (_MoveForward)
						{
							_m_task_list.get(_InnerIndex).set_x(_calculate_x(_InnerIndex));
							_m_task_list.get(_InnerIndex).set_x(_calculate_y(_InnerIndex));
						}
					}
					
					break;
				}
			}
		}
		
		else if (_Action == MotionEvent.ACTION_DOWN)
		{
			
			final float _XValue = _Event.getX();
			final float _YValue = _Event.getY();
			
			boolean _Found = false;
			
			for (int _Index = 0, _Size = _m_task_list.size(); _Index < _Size; ++_Index)
			{
				if (_is_inside_circle(_m_task_list.get(_Index).get_x(), _m_task_list.get(_Index).get_y(), _XValue, _YValue))
				{
					_Found = true;
					
					break;
				}
			}
			
			if (!_Found)
			{
				final float _XCalcedValue = _calculate_x(_m_task_list.size());
				final float _YCalcedValue = _calculate_y(_m_task_list.size());
				
				Task _Task = new Task(_XCalcedValue, _YCalcedValue, 0);
				_m_task_list.add(_Task);
				
				_update_list();
				
				Log.i("TOUCH", ":)");
			}
		}
		
		invalidate();
		
		return true;
	}
	
	// Helper Functions
	
	private void _ctor()
	{
		_m_task_list = new ArrayList<Task>();
		_m_colors = getResources().getIntArray(R.array.colors);
		_m_paint = new Paint();
		_m_view = this.findViewById(R.id._g_task_view);
	}
	
	private float _calculate_x(int _Location)
	{
		float _ReturnValue = 0;
		
		int _Size = _Location;
		
		float _Rows = (float) ((_Size % 2) + .5);
		
		final float _Scale = getContext().getResources().getDisplayMetrics().density;
		
		float _Dip = (float) 300;
		
		_ReturnValue = (_Dip * _Scale + .5f) * _Rows;
		
		return _ReturnValue;
	}
	
	private float _calculate_y(int _Location)
	{
		float _ReturnValue = 0;
		
		int _Size = _Location;
		
		float _Rows = (float) ((_Size / 2) + .5);
		
		final float _Scale = getContext().getResources().getDisplayMetrics().density;
		
		float _Dip = (float) 250;
		
		_ReturnValue = (_Dip * _Scale + .5f) * _Rows;
		
		return _ReturnValue;
	}
	
	private boolean _is_inside_circle(float _TaskXPosition, float _TaskYPosition, float _XPosition, float _YPosition)
	{
		boolean _Return = false;
		
		float _MinX = _TaskXPosition - OUTER_SIZE;
		float _MaxX = _TaskXPosition + OUTER_SIZE;
		
		float _MinY = _TaskYPosition - OUTER_SIZE;
		float _MaxY = _TaskYPosition + OUTER_SIZE;
		
		if (_XPosition > _MinX && _XPosition < _MaxX && _YPosition > _MinY && _YPosition < _MaxY) _Return = true;
		
		return _Return;
	}
	
	private void _update_list()
	{
	   
	   int _LastIndex = _m_task_list.size() - 1;
	   Task _LastTask = _m_task_list.get(_LastIndex);
	   
	   if (_LastIndex % 2 == 0)
	   {
	      
	      Task _TopRight = _m_task_list.get(_LastIndex - 1);
	      Task _Top = _m_task_list.get(_LastIndex - 2);
	      
	      _TopRight.set_bottom_left(_LastTask);
	      _Top.set_bottom(_LastTask);
	      
	      _LastTask.set_top_right(_TopRight);
	      _LastTask.set_top(_Top);
	      
	   }
	   
	}

} // end of class TaskView

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
