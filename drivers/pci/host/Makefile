ifeq ($(CONFIG_MACH_MSM8996_ELSA),y)
EXTRA_CFLAGS += -DMSM8996_ELSA
else ifeq ($(CONFIG_MACH_MSM8996_ANNA),y)
EXTRA_CFLAGS += -DMSM8996_ANNA
else ifeq ($(CONFIG_MACH_MSM8996_H1), y)
EXTRA_CFLAGS += -DMSM8996_H1
endif

obj-$(CONFIG_PCIE_DW) += pcie-designware.o
obj-$(CONFIG_PCI_DRA7XX) += pci-dra7xx.o
obj-$(CONFIG_PCI_EXYNOS) += pci-exynos.o
obj-$(CONFIG_PCI_IMX6) += pci-imx6.o
obj-$(CONFIG_PCI_MVEBU) += pci-mvebu.o
obj-$(CONFIG_PCI_TEGRA) += pci-tegra.o
obj-$(CONFIG_PCI_MSM) += pci-msm.o
obj-$(CONFIG_PCI_RCAR_GEN2) += pci-rcar-gen2.o
obj-$(CONFIG_PCI_RCAR_GEN2_PCIE) += pcie-rcar.o
obj-$(CONFIG_PCI_HOST_GENERIC) += pci-host-generic.o
obj-$(CONFIG_PCIE_SPEAR13XX) += pcie-spear13xx.o
obj-$(CONFIG_PCI_KEYSTONE) += pci-keystone-dw.o pci-keystone.o
obj-$(CONFIG_PCIE_XILINX) += pcie-xilinx.o
obj-$(CONFIG_PCI_XGENE) += pci-xgene.o
obj-$(CONFIG_PCI_XGENE_MSI) += pci-xgene-msi.o
