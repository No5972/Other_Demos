package com.hadoop.word;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class WordCountReducer extends
		Reducer<Text, LongWritable, Text, LongWritable> {

	// dubbo
	// dubbo [1,1,1,1,1,1]
	private LongWritable reducerValueOut = new LongWritable();

	@Override
	protected void reduce(Text key, Iterable<LongWritable> values,
			Context context) throws IOException, InterruptedException {
		int sum = 0;
		// 统计每一个单词所出现的个数
		System.out.println("key==>" + key + "         value==>"
				+ values.toString());
		for (LongWritable value : values) {
			sum += value.get();
		}
		reducerValueOut.set(sum);
		// 将统计后的数据传递给TextOutputForamt，把统计后的数据写入一个文件中
		context.write(key, reducerValueOut);
	}
}
