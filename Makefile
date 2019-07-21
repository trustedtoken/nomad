BUILDDIR   = build
OBJDIR   = obj
BINDIR   = bin

CC = clang
CFLAGS = -std=c99 -pedantic -Wall
LDFLAGS=
SOURCES=$(wildcard *.c) \
	$(wildcard **/*.c)
OBJECTS=$(SOURCES:%.c=$(BUILDDIR)/$(OBJDIR)/%.o)
TARGET=nomad

all: dir $(BUILDDIR)/$(BINDIR)/$(TARGET)

dir:
	@mkdir -p build/{obj,bin}

$(BUILDDIR)/$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Linking complete!"

$(BUILDDIR)/$(OBJDIR)/%.o: %.c %.h
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(BUILDDIR)/$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

clean:
	rm -rf $(BUILDDIR)