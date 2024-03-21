package {	

	import com.cartogrammar.shp.ShpFeature;
	import com.cartogrammar.shp.ShpMap;
	
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.geom.ColorTransform;
		
	/**
	 * An example of drawing a simple map from a shapefile using my ShpMap class and Edwin van Rijkom's library.
	 * 
	 * @author Andy Woodruff (cartogrammar.com/blog)
	 * 
	 */
		
    public class SHPreader extends Sprite
    {
		
		public var loadedMap = new ShpMap("map/map.shp","map/map.dbf");
		
		/*
		// Need to wait for the map to finish loading/drawing before it can be resized correctly.
		private function onMapLoaded(event:Event):void
		{
			// just for fun, add a marker to somewhere around my house!
			addMarkerAt( 42.36,-71.11 );
		}
		
		// To demonstrate retrieving a particular feature and doing something to it. This colors Wisconsin green.
		private function onAttributesLoaded(event:Event):void
		{
			var f : ShpFeature = loadedMap.getFeatureByAttribute("STATE_NAME","Wisconsin");
			if (f != null){
				var cTrans : ColorTransform = new ColorTransform();
				cTrans.color = 0x009933;
				f.transform.colorTransform = cTrans;
			}
		}
		
		// Super basic method for adding a green box at a specified lat/long.
		private function addMarkerAt( lat : Number, lon : Number )  : void
		{
			var box : Sprite = new Sprite();
			box.graphics.lineStyle(1,0,1,false,"none");
			box.graphics.beginFill(0x009933);
			box.graphics.drawRect(-.5,-.5,1,1);
			box.graphics.endFill();
			loadedMap.addMarker(lat,lon,box);
		}
		*/
        
    }		
}