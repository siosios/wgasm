#!/bin/bash
#
#	----------------------------------------------------------------------------
#	Include file for processing and validate GAMETYPEID value
#	============================================================================
#	Created:       2024-05-19, by Weasel.SteamID.155@gMail.com        
#	Last modified: 2024-05-27, by Weasel.SteamID.155@gMail.com
#	----------------------------------------------------------------------------
#
#	USAGE NOTES:
#
#	Includes stuff such as ...
#	
#		Ensure gametypeid has been passed (not blank/empty)
#		Ensure gametypeid is lower-case alpha-numeric (plus "-") only.
#		Throw errors if any of that is not true.
#
#	----------------------------------------------------------------------------
#
#	If verbose is on, display progress notification ...
#
if [ "$SCRIPTS_VERBOSE" == true ]; then
	MESSAGE="[Processing include file: ${ANSI_CYANLT}include-gametypeid.inc${ANSI_OFF} (via ${ANSI_WHITE}${0##*/}${ANSI_OFF})${ANSI_OFF}]";
	if [ -t 1 ]; then
			echo -e "$MESSAGE";
            	else
			echo -e "$MESSAGE" | ansi2txt;
    fi;
fi;
#
#	Process GAMETYPEID:
#
#		Check that GAMETYPEID is only lower-case alpha-numeric ...
#
TEMP_GAMETYPEID=$(echo $GAMETYPEID | tr -cd [0-9a-z]-);
if [ "$TEMP_GAMETYPEID" != "$GAMETYPEID" ]; then
	MESSAGE="${ANSI_REDLT}$(figlet "Error:")${ANSI_OFF}\n";
	MESSAGE+="${ANSI_WHITE}Only lower-case alpha-numeric charaters (and "-") permitted in parameter: ${ANSI_REDLT}gametypeid${ANSI_OFF}";
	echo -e "$MESSAGE";
	if [[ $SCRIPT_LOG_FILE ]]; then
		echo -e "$MESSAGE" | ansi2txt >> "$SCRIPT_LOG_FILE";
	fi;
	#
	#	Display end of stuff ...
	#
	source $SCRIPTS_FOLDER/include/include-outputend.inc;
    exit 1;
fi;
#
#	Check that GAMESERVERID has been provided ...
#
if ! [[ $TEMP_GAMETYPEID ]]; then
	MESSAGE="${ANSI_REDLT}$(figlet "Error:")${ANSI_OFF}\n";
	MESSAGE+="${ANSI_WHITE}Missing (required) parameter: ${ANSI_REDLT}gametypeid${ANSI_OFF}";
	echo -e "$MESSAGE";
	if [[ $SCRIPT_LOG_FILE ]]; then
		echo -e "$MESSAGE" | ansi2txt >> "$SCRIPT_LOG_FILE";
	fi;
	#
	#	Display end of stuff ...
	#
	source $SCRIPTS_FOLDER/include/include-outputend.inc;
    exit 1;
fi;
#
#	If verbose is on, display some stuff ...
#
if [ "$SCRIPTS_VERBOSE" == true ]; then
    echo -e "Option:                       Value:";  
    echo -e "----------------------------  -----";
    echo -e "Verbose mode:                 $SCRIPTS_VERBOSE";
    echo -e "Game-Type ID:                 $GAMETYPEID";
	echo -e "----------------------------  -----";
fi;
#
#	If verbose is on, display progress notification ...
#
if [ "$SCRIPTS_VERBOSE" == true ]; then
	MESSAGE="[Finished include file: ${ANSI_CYANLT}include-gametypeid.inc${ANSI_OFF} (via ${ANSI_WHITE}${0##*/}${ANSI_OFF})${ANSI_OFF}]";
	if [ -t 1 ]; then
			echo -e "$MESSAGE";
            	else
			echo -e "$MESSAGE" | ansi2txt;
    fi;
fi;
#
#	... thats all folks!
#
