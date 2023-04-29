import java.awt.{Color}

object E2 {
	def getClock(hour:Int,min:Int):List[Shape] = {
		List(Circle(0.5,0.5,0.5,Color.GRAY),Line(0.5,0.5,0.5+(0.5*Math.cos((Math.PI/2)-(2*Math.PI*min/60))),0.5+(0.5*Math.sin((Math.PI/2)-(2*Math.PI*min/60))),Color.RED),Line(0.5,0.5,0.5+(0.4*Math.cos((Math.PI/2)-(2*Math.PI*hour/12))),0.5+(0.4*Math.sin((Math.PI/2)-(2*Math.PI*hour/12))),Color.BLUE))
	}
}
