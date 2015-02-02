cmake_minimum_required(VERSION 2.6)
    file(GLOB test_srcs "*.cpp")
    foreach(src ${test_srcs})
        get_filename_component(targetName ${src} NAME_WE)
        message("target: " ${targetName})
        add_executable(${targetName} ${src})
        add_custom_target(${targetName}.run ${targetName} ./${targetName})
        
			add_custom_target(valgrind_${targetName} 
				COMMAND  ${targetName} &
				valgrind
					--leak-check=full
					--show-reachable=yes
					--track-fds=yes
					--error-exitcode=1
					--track-origins=yes
					--tool=memcheck
					#--log-file=${CMAKE_CURRENT_BINARY_DIR}/valgrind.log.${case_name}
					${CMAKE_CURRENT_BINARY_DIR}/${targetName}
				WORKING_DIRECTORY
					${CMAKE_CURRENT_BINARY_DIR}
			)
		target_link_libraries(${targetName} cppunitlite)
	endforeach(src)
	