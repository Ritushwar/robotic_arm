import math
import numpy as np

def get_fk_matrix(angles, length):
    final_matrix = np.zeros((4,4))
    print(length[2])
    ang = np.deg2rad(angles)
    v_00 = np.cos(ang[0])*np.cos(ang[1] + ang[2] + ang[3])
    final_matrix[0,0] = v_00

    v_01 = -np.cos(ang[0])*np.sin(ang[1] + ang[2] + ang[3])
    final_matrix[0,1] = v_01

    v_03 = np.cos(ang[0])*(length[4] * np.cos(ang[1] + ang[2] + ang[3]) + length[3] * np.cos(ang[1] + ang[2]) + length[2] * np.cos(ang[1])) + length[1] * np.cos(ang[0])
    final_matrix[0,3] = v_03

    v_10 = np.sin(ang[0]) * np.cos(ang[1] + ang[2] + ang[3])
    final_matrix[1,0] = v_10

    v_11 = - np.sin(ang[0]) * np.sin(ang[1] + ang[2] + ang[3])
    final_matrix[1,1] = v_11

    v_13 = np.sin(ang[0])*(length[4] * np.cos(ang[1] + ang[2] + ang[3]) + length[3] * np.cos(ang[1] + ang[2]) + length[2] * np.cos(ang[1])) + length[1] * np.sin(ang[0])
    final_matrix[1,3] = v_13

    v_20 = - np.sin(ang[1] + ang[2] + ang[3])
    final_matrix[2,0] = v_20

    v_21 = - np.cos(ang[1] + ang[2] + ang[3])
    final_matrix[2,1] = v_21

    v_23 = -length[4] * np.sin(ang[1] + ang[2] + ang[3]) - length[3] * np.sin(ang[1] + ang[2]) - length[2] * np.sin(ang[1]) + length[0]
    final_matrix[2,3] = v_23

    v_33 = 1
    final_matrix[3,3] = v_33

    return final_matrix

def main():
    angles = np.zeros(4)
    length = np.zeros(5)
    print("Enter the following parameter")
    theta_1 = float(input("theta 1: "))
    angles[0] = theta_1
    theta_2 = float(input("theta 2: "))
    angles[1] = theta_2
    theta_3 = float(input("theta 3: "))
    angles[2] = theta_3
    theta_4 = float(input("theta 4: "))
    angles[3] = theta_4

    l2 = float(input("l2: "))
    length[0] = l2
    l3 = float(input("l3: "))
    length[1] = l3
    l4 = float(input("l4: "))
    length[2] = l4
    l5 = float(input("l5: "))
    length[3] = l5
    l6 = float(input("l6: "))
    length[4] = l6
    # print(angles)
    # print(length)
    fk_matrix = get_fk_matrix(angles, length)
    print(fk_matrix)

if __name__ == "__main__":
    main()
