object A2 {
	def trim(s : String, f: Char => Boolean) : String = {
		s.dropWhile(f).reverse.dropWhile(f).reverse
	}
}

