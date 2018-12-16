package io.github.no5972.springbootdemo.dao;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;

import io.github.no5972.springbootdemo.models.Manager;

@Mapper
public interface ManagerDao {
	public List<Manager> getAllManagers();
}
