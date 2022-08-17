-- Solution
workspace "playground"
 configurations { "Debug", "Release" }
 architecture "x64"
 startproject "pg"

project "pg"
 kind "ConsoleApp"
 language "C++"

 files { "src/**.h", "src/**.cpp" }