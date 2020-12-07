use std::fs::File;
use std::io::{BufReader, BufRead};
use std::error::Error;
use std::result::Result;

fn is_valid(password: &str, c: char, pos1: usize, pos2: usize) -> bool {
	let b = password.as_bytes();
	
	return (b[pos1 - 1] as char == c) ^ (b[pos2 - 1] as char == c);
}

fn main() -> Result<(), Box<dyn Error>> {
	let lines = BufReader::new(File::open("input.txt")?).lines();

	let mut valid = 0;
	for line in lines {
		let line = line?;

		let mut v = line.split(|c| c == '-' || c == ':' || c == ' ');
		let pos1 = v.next().unwrap().parse::<usize>()?;
		let pos2 = v.next().unwrap().parse::<usize>()?;
		let c = v.next().unwrap().parse::<char>()?;
		v.next().unwrap();
		let password = v.next().unwrap();

		valid += match is_valid(password, c, pos1, pos2) {
			true => 1,
			false => 0		
			};
	}

	print!("{}\n", valid);
	Ok(())
}
