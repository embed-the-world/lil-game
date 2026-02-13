
# download that damn font

## check defines
if(NOT DEFINED FONT_DIR)
	message(FATAL_ERROR "FONT_DIR is not defined before including download_font.cmake")
endif()
if(NOT DEFINED FONT_FILE)
	message(FATAL_ERROR "FONT_FILE is not defined before including download_font.cmake")
endif()

# make font dir
file(MAKE_DIRECTORY "${FONT_DIR}")

message(STATUS "Downloading Roboto-Regular.ttf...")

file(
	DOWNLOAD
		"https://fonts.gstatic.com/s/roboto/v30/KFOmCnqEu92Fr1Mu4mxP.ttf"
		"${FONT_FILE}"
	SHOW_PROGRESS
	EXPECTED_HASH SHA256=a9ef021078603005c0b08fba881f1a7eb62ef213238021f3e8a4a00daa60b9d6
	STATUS status
)

list(GET status 0 status_code)
list(GET status 1 status_msg)

if(NOT status_code EQUAL 0)
	message(FATAL_ERROR "Failed to download font: ${status_msg}")
endif()

message(STATUS "Font downloaded to: ${FONT_FILE}")
