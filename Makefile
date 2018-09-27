.PHONY: clean All

All: release debug

debug:
	@echo "----------Building project:[ find-shortest-path-by-dijsktra-algorithm - Debug ]----------"
	@"$(MAKE)" -f  "Makefile_debug.mk"

release:
	@echo "----------Building project:[ find-shortest-path-by-dijsktra-algorithm - Release ]----------"
	@"$(MAKE)" -f  "Makefile_release.mk"
	
clean:
	@echo "----------Cleaning project:[ find-shortest-path-by-dijsktra-algorithm - Debug ]----------"
	@"$(MAKE)" -f  "Makefile_debug.mk" clean
	@"$(MAKE)" -f  "Makefile_release.mk" clean
