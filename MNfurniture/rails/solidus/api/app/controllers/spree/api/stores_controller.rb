# frozen_string_literal: true

module Spree
  module Api
    class StoresController < Spree::Api::BaseController
      before_action :get_store, except: [:index, :create]

      def index
        authorize! :index, Store
        @stores = Spree::Store.accessible_by(current_ability).all
        respond_with(@stores)
      end

      def create
        authorize! :create, Store
        @store = Spree::Store.new(store_params)
        @store.code = params[:store][:code]
        if @store.save
          respond_with(@store, status: 201, default_template: :show)
        else
          invalid_resource!(@store)
        end
      end

      def update
        authorize! :update, @store
        if @store.update(store_params)
          respond_with(@store, status: 200, default_template: :show)
        else
          invalid_resource!(@store)
        end
      end

      def show
        authorize! :show, @store
        respond_with(@store)
      end

      def destroy
        authorize! :destroy, @store
        @store.destroy
        respond_with(@store, status: 204)
      end

      private

      def get_store
        @store = Spree::Store.find(params[:id])
      end

      def store_params
        params.require(:store).permit(permitted_store_attributes)
      end
    end
  end
end
