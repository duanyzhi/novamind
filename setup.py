import setuptools
import sys
with open("README.md", "r") as fh:
    long_description = fh.read()

from pybind11.setup_helpers import Pybind11Extension

ext_modules = [
    Pybind11Extension(
        "python_example",
        sorted(glob("src/*.cpp")),  # Sort source files for reproducibility
    ),
]

setuptools.setup(
    name="novamind",
    version="0.0.2",
    author="Nova Mind",
    author_email="duanyzhi@outlook.com",
    description="Learning",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/duanyzhi/novamind",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent"
    ],
)
