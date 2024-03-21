package com.cartogrammar.shp
{
	import flash.geom.Point;
	
	import org.vanrijkom.shp.ShpPoint;
	import org.vanrijkom.shp.ShpRecord;
	
	/**
	 * A display object for a single point feature.
	 * @author Andy Woodruff
	 * 
	 */
	public class PointFeature extends ShpFeature
	{
		private var geometry : Point;
		
		public function PointFeature(record:ShpRecord)
		{
			super();
			var shpPoint : ShpPoint = record.shape as ShpPoint;
			geometry = new Point( shpPoint.x, shpPoint.y );
			/* 	If a different map projection were desired, then here
				we could run the point through a transformation formula. */
				
			draw();
		}
		
		override public function draw():void
		{
			graphics.clear();
			graphics.beginFill(0);
			graphics.drawCircle(0,0,.5);
			this.x = geometry.x;
			this.y = -geometry.y;
		}
		
	}
}