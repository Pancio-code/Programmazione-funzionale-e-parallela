object E4 {
	def repeat(l : Int)(body: =>Unit): Unit = {
		if( l < 1) ()
		else {
			body
			repeat(l -1)(body)
		}
	}
}
