#cmake file for project association                     #表示注释
#author:>---LDE Team
#created:>--2015/08/16

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)                  #cmake 最低版本要求
                                                        #低于2.8.11 构建过程会被终止

PROJECT(src)                                 #定义工程名称

MESSAGE(STATUS "Project: LDE")                       #打印相关消息消息
MESSAGE(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

# SET(CMAKE_BUILE_TYPE DEBUG)                             #指定编译类型


# SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")                     #指定编译器

ADD_SUBDIRECTORY(ldeinit)                               #添加子目录
ADD_SUBDIRECTORY(ldeabout)
ADD_SUBDIRECTORY(loogout)
ADD_SUBDIRECTORY(lrun)
ADD_SUBDIRECTORY(ldecc)
ADD_SUBDIRECTORY(lcalc)
ADD_SUBDIRECTORY(loofm)
ADD_SUBDIRECTORY(Looget)
ADD_SUBDIRECTORY(looplorer)
ADD_SUBDIRECTORY(Lootepad)

INSTALL(DIRECTORY ../share/ DESTINATION /usr/share/applications)
INSTALL(PROGRAMS ../shell/startlde DESTINATION /usr/bin)
INSTALL(FILES ../xsessions/LDE.desktop DESTINATION /usr/share/xsessions)
INSTALL(FILES ../wallpapers/lde-default.png DESTINATION /usr/share/wallpapers)
INSTALL(FILES ../xsessions/LDE.desktop DESTINATION /usr/share/apps/kdm/sessions)
