// Scrivere la soluzione qui...

import java.awt.{Color}

object E2 {
    def getClock(hour:Int, min:Int):List[Shape] = {
        val ml = 0.5
        val hl = 0.4
        val ma = Math.PI/2-min*2*Math.PI/60
        val ha = Math.PI/2-hour*2*Math.PI/12
        List(Circle(0.5,0.5,0.5,Color.GRAY), 
             Line(0.5, 0.5, 0.5+ml*Math.cos(ma), 0.5+ml*Math.sin(ma), Color.RED),
             Line(0.5, 0.5, 0.5+hl*Math.cos(ha), 0.5+hl*Math.sin(ha), Color.BLUE)) 
    }
}