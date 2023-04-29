object A2 {
	implicit def IntToMyInt(i: Int) : MyInt = new MyInt(i)
}

case class MyInt(i :Int) {
	def minMax(s:Int) : (Int,Int) = {
		if(i > s) (s,i) else (i,s)
	}
}
