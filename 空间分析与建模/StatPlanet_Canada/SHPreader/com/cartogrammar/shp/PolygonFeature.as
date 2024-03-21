package com.cartogrammar.shp
{
	import flash.geom.Rectangle;
	
	import org.vanrijkom.shp.ShpPolygon;
	import org.vanrijkom.shp.ShpRecord;
	
	/**
	 * A display object for a single polygon feature.
	 * @author Andy Woodruff
	 * 
	 */
	public class PolygonFeature extends ShpFeature
	{
		/**
		 * Polygon geometry consists of one or more rings of points.
		 * Each ring is an Array and defines a separate polygon.
		 * (Consider Hawaii as a polygon feature: it is one feature
		 * consisting of several separate shapes, i.e. islands.)
		 */
		private var geometry : Array;
		
		public function PolygonFeature(record:ShpRecord)
		{
			super();
			geometry = (record.shape as ShpPolygon).rings;
			/* 	If a differen map projection were desired, then here
				we could run each point in geometry through a
				transformation formula. */
				
			draw();
		}
		
		override public function draw():void
		{
			shape.graphics.clear();
			var ring:Array = new Array();
			var i : int = new int;
			//shape.graphics.lineStyle(1,0x666666,1,false,"none");
			for each ( ring in geometry ) {
				shape.graphics.moveTo( ring[0].x*scaleFactor, -ring[0].y*scaleFactor );
				shape.graphics.beginFill(0xcccccc);
				for ( i = 1; i < ring.length; i ++ ) {
					shape.graphics.lineTo( ring[i].x*scaleFactor, -ring[i].y*scaleFactor );
				}
				shape.graphics.endFill();
			}
			boundary.graphics.clear();
			boundary.graphics.lineStyle(1,0x666666,1,false,"none");
			for each ( ring in geometry ) {
				boundary.graphics.moveTo( ring[0].x*scaleFactor, -ring[0].y*scaleFactor );
				for ( i = 1; i < ring.length; i ++ ) {
					boundary.graphics.lineTo( ring[i].x*scaleFactor, -ring[i].y*scaleFactor );
				}
				//shape.graphics.endFill();
			}
			
			boundary.scaleX = boundary.scaleY = shape.scaleX = shape.scaleY = 1/scaleFactor;	// see comment on scaleFactor in ShpFeature.as
			addChild(shape);
			addChild(boundary);
			
			var bounds : Rectangle = shape.getBounds(this);
			boundary.x = shape.x = -bounds.x;
			boundary.y = shape.y = -bounds.y;
			this.x = bounds.x;
			this.y = bounds.y;
		}
		
	}
}