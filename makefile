COMPILER= g++
OPTIONS=
COMPILE=$(COMPILER) $(OPTIONS)
COMPONENTS=src/components
BUILD=build_area

# Compile main by default
all: run

# $(BUILD)/*.o expands to all .o files in the $(BUILD) directory
# In this case, we'll get $(BUILD)/file1.o $(BUILD)/file2.o
run: src/main.cpp $(BUILD)/Message.o $(BUILD)/EventQueue.o $(BUILD)/Node.o $(BUILD)/Router.o $(BUILD)/sim_engine.o $(BUILD)/RecvEvent.o $(BUILD)/SendEvent.o $(BUILD)/InterfaceLinkEntry.o $(BUILD)/Link.o $(BUILD)/NetworkInterface.o
	$(COMPILER) $< $(BUILD)/*.o -o $@

# Message
$(BUILD)/Message.o: $(COMPONENTS)/message/Message.cpp $(COMPONENTS)/message/Message.h build_area
	$(COMPILE) -c $< -o $@

# Device
$(BUILD)/Node.o: $(COMPONENTS)/device/Node.cpp $(COMPONENTS)/device/Node.h build_area
	$(COMPILE) -c $< -o $@

$(BUILD)/Router.o: $(COMPONENTS)/device/Router.cpp $(COMPONENTS)/device/Router.h build_area
	$(COMPILE) -c $< -o $@

# Driver
$(BUILD)/sim_engine.o: $(COMPONENTS)/driver/sim_engine.cpp $(COMPONENTS)/driver/sim_engine.h build_area
	$(COMPILE) -c $< -o $@

# Event
$(BUILD)/EventQueue.o: $(COMPONENTS)/event/EventQueue.cpp $(COMPONENTS)/event/EventQueue.h $(COMPONENTS)/event/Event.h build_area
	$(COMPILE) -c $< -o $@

$(BUILD)/SendEvent.o: $(COMPONENTS)/event/SendEvent.cpp $(COMPONENTS)/event/SendEvent.h $(COMPONENTS)/event/Event.h build_area
	$(COMPILE) -c $< -o $@

$(BUILD)/RecvEvent.o: $(COMPONENTS)/event/RecvEvent.cpp $(COMPONENTS)/event/RecvEvent.h $(COMPONENTS)/event/Event.h $(COMPONENTS)/linking/ConnectionInterface.h build_area
	$(COMPILE) -c $< -o $@

# Linking
$(BUILD)/InterfaceLinkEntry.o: $(COMPONENTS)/linking/InterfaceLinkEntry.cpp $(COMPONENTS)/linking/InterfaceLinkEntry.h build_area
	$(COMPILE) -c $< -o $@

$(BUILD)/Link.o: $(COMPONENTS)/linking/Link.cpp $(COMPONENTS)/linking/Link.h build_area
	$(COMPILE) -c $< -o $@

$(BUILD)/NetworkInterface.o: $(COMPONENTS)/linking/NetworkInterface.cpp $(COMPONENTS)/linking/NetworkInterface.h build_area
	$(COMPILE) -c $< -o $@



# Make the build directory if it doesn't exist
build_area:
	mkdir -p $(BUILD)

# Delete the build directory and program
clean:
	rm -rf $(BUILD) program

# These rules do not correspond to a specific file
.PHONY: build clean


