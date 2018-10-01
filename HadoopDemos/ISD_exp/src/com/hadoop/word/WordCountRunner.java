package com.hadoop.word;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class WordCountRunner implements Tool {

	//
	private Configuration configuration = null;

	@Override
	public int run(String[] args) throws Exception {
		// 组装Mapper 和 Reducer

		// 1 获取配置信息，或者job对象实例
		// 09-11注：此处需要加一句设置yarn，才能让jar把job分配到集群运行。
		configuration.set("mapreduce.framework.name", "yarn");  
		//configuration.set("yarn.resourcemanager.address", "master:8032");  
		Job job = Job.getInstance(configuration, "wordCount99");
		// 2 指定本程序的jar包所在的本地路径
		job.setJarByClass(WordCountRunner.class);
		// 3 关联mapper/Reducer业务类
		job.setMapperClass(WordCountMapper.class);
		job.setReducerClass(WordCountReducer.class);
		// 4 指定mapper输出数据的kv类型
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(LongWritable.class);
		// 5 指定最终输出的数据的kv类型
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(LongWritable.class);
		// 6 指定job的输入数据路径和输出数据路径
		FileInputFormat.addInputPath(job,
				new Path("hdfs://192.168.244.161:9000/exp_4/wordData.txt"));
		FileOutputFormat.setOutputPath(job, new Path(
				"hdfs://192.168.244.161:9000/exp_4/output"));
		// FileInputFormat.addInputPath(job,new Path(args[0]));
		// FileOutputFormat.setOutputPath(job,new Path(args[1]));
		// 7 提交

		return job.waitForCompletion(true) ? 0 : 1;
	}

	@Override
	public void setConf(Configuration configuration) {
		this.configuration = configuration;
	}

	@Override
	public Configuration getConf() {
		return configuration;
	}

	public static void main(String[] args) throws Exception {
		int status = ToolRunner.run(new WordCountRunner(), args);
		System.exit(status);
	}
}
