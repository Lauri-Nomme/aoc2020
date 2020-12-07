use std::fs::File;
use std::io::{BufReader, BufRead};
use std::error::Error;
use std::result::Result;

fn is_valid(password: &str, c: char, min: u32, max: u32) -> bool {
	let mut count = 0;
	for cc in password.chars() {
		if cc == c {
			count = count + 1;
			if count > max {
				return false;
			}
		}
	}

	return count >= min;
}

fn main() -> Result<(), Box<dyn Error>> {
	let lines = BufReader::new(File::open("input.txt")?).lines();

	let mut valid = 0;
	for line in lines {
		let line = line?;

		let mut v = line.split(|c| c == '-' || c == ':' || c == ' ');
		let min = v.next().unwrap().parse::<u32>()?;
		let max = v.next().unwrap().parse::<u32>()?;
		let c = v.next().unwrap().parse::<char>()?;
		v.next().unwrap();
		let password = v.next().unwrap();

		valid += match is_valid(password, c, min, max) {
			true => 1,
			false => 0		
			};
	}

	print!("{}\n", valid);
	Ok(())
}
