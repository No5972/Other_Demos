package io.github.no5972.hadoop.fileiodemo;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.apache.hadoop.conf.Configuration;  
import org.apache.hadoop.fs.FileSystem;  
import org.apache.hadoop.fs.Path; 
import org.junit.Test;


public class HDFSClient {
	
	//上传文件
	@Test
	public static void testUploadFile() throws URISyntaxException, IOException, InterruptedException {
		//1. 获取连接
		Configuration configuration = new Configuration();
		FileSystem fileSystem = FileSystem.get(new URI("hdfs://192.168.244.161:9000"), configuration, "zkpk");
		//2. 上传文件
		fileSystem.copyFromLocalFile(false, false, new Path("../../Desktop/jdk-7u71-linux-x64.gz"), new Path("/exp_5/jdk-7u71-linux-x64.gz"));
		//3. 关闭连接，释放资源
		fileSystem.close();
	}

	//下载文件
	public static void testDownloadFile() throws IllegalArgumentException, IOException, InterruptedException, URISyntaxException {
		//1. 获取连接
		Configuration configuration = new Configuration();
		FileSystem fileSystem = FileSystem.get(new URI("hdfs://192.168.244.161:9000"), configuration, "zkpk");
		//2. 下载文件
		fileSystem.copyToLocalFile(false, new Path("/exp_5/jdk-7u71-linux-x64.gz"), new Path("../../Desktop/exp_5/jdk-7u71-linux-x64.gz"), true);
		//3. 关闭连接，释放资源
		fileSystem.close();
	}
	public static void main(String[] args) throws IllegalArgumentException, IOException, InterruptedException, URISyntaxException {
		System.out.println("Start Uploading");
		testUploadFile();
		System.out.println("Upload Ends");
		System.out.println("Start Downloading");
		testDownloadFile();
		System.out.println("Download Ends");
		
	}
}