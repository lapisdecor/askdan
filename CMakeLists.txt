cmake_minimum_required(VERSION 3.10)

project(Askdan)

add_subdirectory(src)

# Configure the CSV file to be copied to the build dir
configure_file(
	$(CMAKE_SOURCE_DIR)/../package_list.csv
	src/package_list.csv
	COPYONLY
)

# Configurar a instalação
install(
    TARGETS askdan
    RUNTIME DESTINATION bin
)

# Copiar a o ficheiro csv
install(
	FILES package_list.csv
	DESTINATION data/
)
