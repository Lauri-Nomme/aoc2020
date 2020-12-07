use std::fs::File;
use std::io::{BufReader, BufRead};
use std::error::Error;
use std::result::Result;
use byte_set::ByteSet;

fn main() -> Result<(), Box<dyn Error>> {
    let mut sum_group_unique_questions = 0;
    let lines = BufReader::new(File::open("input.txt")?).lines();

    let mut group_unique_questions = ByteSet::new();
    for line in lines {
        let line = line?;
        if line.is_empty() {
            sum_group_unique_questions += group_unique_questions.len();
            group_unique_questions.clear();
            continue;
        }

        group_unique_questions.extend(line.as_bytes())
    }

    sum_group_unique_questions += group_unique_questions.len();

    print!("{}\n", sum_group_unique_questions);
    Ok(())
}