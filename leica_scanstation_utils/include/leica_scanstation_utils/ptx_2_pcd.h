#pragma once
#ifndef __PTX_2_PCD_H__
#define __PTX_2_PCD_H__

#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <eigen3/Eigen/Dense>

#include <iostream>

#endif 

class ptx_2_pcd
{

public:

    /**
     * @brief Construct a new ptx 2 pcd object
     * 
     */
    ptx_2_pcd(){};

    /**
     * @brief Destroy the ptx 2 pcd object
     * 
     */
    ~ptx_2_pcd(){};

    /**
     * @brief Perform conversion
     * 
     */
    void operator()(const std::string &);

private:

    /** @brief   Number of matrix rows  */
    int _rows{};
    
    /** @brief   Number of matrix cols  */
    int _cols{};

    /** @brief   Cloud's points transformation matrix */
    Eigen::Matrix4f _point_tf{};

    /** @brief   Scanner's POV transformation matrix  */
    Eigen::Matrix<float, 4, 3> _scan_tf;

    /**
     * @brief  Parse and extract file extension
     * 
     * @return std::string Filename's extension
     */
    std::string extension(const std::string &) noexcept;

    /**
     * @brief  Performs conversion from ASCII to float until it finds EOL character
     * 
     * @return std::vector<float> Converted line
     */
    std::vector<float> parseLine(const std::string &);

    /**
     * @brief Extracts the point from a line, applying a transformation in the processes
     * 
     * @return std::string 3D processed point
     */
    std::string processPointLine(const std::vector<float> &);

    /**
     * @brief Applies scanner transformation matrix to a point
     * 
     * @return std::string 3D transformed point
     */
    std::string transformPoint(const Eigen::Vector4f &);

    /**
     * @brief Fills in place an Eigen Matrix row with data from a std::vector
     * 
     * @tparam T Fundamental type of matrix's data
     * @tparam Rows Number of rows
     * @tparam Cols Number of columns
     */
    template <typename T, int Rows, int Cols>
    void fillMatrixRow(Eigen::Matrix<T, Rows, Cols> &, const std::vector<T> &, int);

    /**
     * @brief pcd file header builder
     * 
     * @return std::string File header
     */
    std::string buildHeader();
};