package com.cartogrammar.shp
{
	import flash.display.Sprite;
	import flash.utils.Dictionary;

	/**
	 * Just a base class for point, polyline, and polygon features.
	 * 
	 * @author Andy Woodruff
	 */
	public class ShpFeature extends Sprite
	{
		/**
		 * A factor by which to increase the scale at which data are drawn and then shrunk down again.
		 * The reason for this is that geo-data are dealt with in terms of lat/long, which means
		 * very tiny distances for certain data sets. There is some minimum distance that Flash can
		 * draw, but we can fake it by drawing everything huge and then scaling the whole thing down
		 * afterward.
		 */
		protected var scaleFactor : Number = 500;
		
		/**
		 * Attribute values, with field names as keys. (If a DBF file was loaded.) 
		 */
		public var values : Dictionary;
		
		//protected var shape : Sprite = new Sprite();
		public var shape : Sprite = new Sprite();
		public var boundary : Sprite = new Sprite();
		
		public function ShpFeature()
		{
			super();
		}
		
		/**
		 * Draw the feature. 
		 */
		public function draw() : void
		{
			// override in subclasses
		}
		
	}
}