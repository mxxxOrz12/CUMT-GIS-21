package com.cartogrammar.shp
{
	import org.vanrijkom.shp.ShpPolyline;
	import org.vanrijkom.shp.ShpRecord;
	
	import flash.geom.Rectangle;

	/**
	 * A display object for a single polyline feature.
	 * @author Andy Woodruff
	 * 
	 */
	public class PolylineFeature extends ShpFeature
	{
		/**
		 * Polyline geometry consists of one or more rings of points.
		 * Each ring is an Array and defines a separate line.
		 */
		private var geometry : Array;
		
		public function PolylineFeature(record:ShpRecord)
		{
			super();
			geometry = (record.shape as ShpPolyline).rings;
			/* 	If a different map projection were desired, then here
				we could run each point in geometry through a
				transformation formula. */
				
			draw();
		}
		
		override public function draw():void
		{
			shape.graphics.clear();
			shape.graphics.lineStyle(2,0x333333,1,false,"none");
			for each ( var ring:Array in geometry ) {
				shape.graphics.moveTo( ring[0].x*scaleFactor, -ring[0].y*scaleFactor );
				for ( var i : int = 1; i < ring.length; i ++ ) {
					shape.graphics.lineTo( ring[i].x*scaleFactor, -ring[i].y*scaleFactor );
				}
			}
			shape.scaleX = shape.scaleY = 1/scaleFactor;	// see comment on scaleFactor in ShpFeature.as
			addChild(shape);
			
			var bounds : Rectangle = shape.getBounds(this);
			shape.x = -bounds.x;
			shape.y = -bounds.y;
			this.x = bounds.x;
			this.y = bounds.y;
		}
	}
}