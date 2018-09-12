package com.hadoop.word;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class WordCountMapper extends
		Mapper<LongWritable, Text, Text, LongWritable> {

	private Text mapperKeyOut = new Text();
	private LongWritable mapperValueOut = new LongWritable(1);

	@Override
	protected void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {

		String line = value.toString();
		// 1 、根据空格将这一行切分成单词
		String[] words = line.split(" ");
		// 2 、将切割后的单词拼接成<单词，1>
		for (String word : words) {
			mapperKeyOut.set(word);
			context.write(mapperKeyOut, mapperValueOut);
		}

	}
}
